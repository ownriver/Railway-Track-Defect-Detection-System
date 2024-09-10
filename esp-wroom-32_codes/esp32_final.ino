#include "secrets.h"
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include "WiFi.h"
#include <ArduinoJson.h>
#include <Wire.h>
#include <HardwareSerial.h>
#include <TinyGPS++.h>
#include <driver/i2s.h>

// AWS IoT MQTT Topics
#define AWS_IOT_PUBLISH_TOPIC   "esp32/pub"
#define AWS_IOT_SUBSCRIBE_TOPIC "esp32/sub"

// I2S configuration for INMP441
#define I2S_WS 15      // I2S word select pin (also called LRCL or WS)
#define I2S_SD 13      // I2S serial data pin (SD)
#define I2S_SCK 14     // I2S clock pin (SCK)

// GPS setup (using UART2 on GPIO16 and GPIO17)
TinyGPSPlus gps;
HardwareSerial gpsSerial(2);  // GPS on UART2

// WiFi and MQTT setup
WiFiClientSecure net;
PubSubClient client(net);

// I2S audio configuration for INMP441
void i2sInit() {
  i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
    .sample_rate = 16000,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
    .communication_format = I2S_COMM_FORMAT_I2S,
    .intr_alloc_flags = 0, // Default interrupt priority
    .dma_buf_count = 8,
    .dma_buf_len = 64,
    .use_apll = false
  };

  i2s_pin_config_t pin_config = {
    .bck_io_num = I2S_SCK,
    .ws_io_num = I2S_WS,
    .data_out_num = I2S_PIN_NO_CHANGE,
    .data_in_num = I2S_SD
  };

  i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
  i2s_set_pin(I2S_NUM_0, &pin_config);
  i2s_set_clk(I2S_NUM_0, 16000, I2S_BITS_PER_SAMPLE_16BIT, I2S_CHANNEL_MONO);
}

// Function to get GPS coordinates from NEO-6M GPS module
String getGPSCoordinates() {
  String gpsData = "";
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
  }

  if (gps.location.isValid()) {
    gpsData = String(gps.location.lat(), 6) + "," + String(gps.location.lng(), 6);
  } else {
    gpsData = "0.000000,0.000000";  // If GPS data is not valid
  }

  return gpsData;
}

// Function to capture audio from INMP441 microphone
String captureAudio() {
  size_t bytesRead;
  int16_t audioBuffer[1024];
  
  // Read audio data from I2S
  i2s_read(I2S_NUM_0, &audioBuffer, sizeof(audioBuffer), &bytesRead, portMAX_DELAY);

  // For simplicity, we return a dummy base64 string here (in real usage, you would convert audio data to base64)
  return "dummy_audio_base64_string";  // Replace with actual base64 encoding of audioBuffer
}

void connectAWS() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.println("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("Connected to WiFi");

  // Configure the client with AWS IoT root certificate, device certificate, and private key
  net.setCACert(AWS_CERT_CA);
  net.setCertificate(AWS_CERT_CRT);
  net.setPrivateKey(AWS_CERT_PRIVATE);

  // Set MQTT broker endpoint and port
  client.setServer(AWS_IOT_ENDPOINT, 8883);

  while (!client.connected()) {
    Serial.print("Connecting to AWS IoT...");
    if (client.connect(THINGNAME)) {
      Serial.println("Connected to AWS IoT");
      client.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);  // Subscribe to the topic
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" trying again in 5 seconds");
      delay(5000);
    }
  }
}

void publishMessage() {
  StaticJsonDocument<1024> doc;
  doc["device_id"] = millis();

  // Get real GPS coordinates from NEO-6M GPS module
  String gpsData = getGPSCoordinates();
  int commaIndex = gpsData.indexOf(',');
  String gpsLat = gpsData.substring(0, commaIndex);
  String gpsLon = gpsData.substring(commaIndex + 1);

  doc["GPS_lat"] = gpsLat;
  doc["GPS_lon"] = gpsLon;

  // Capture audio data from INMP441
  doc["audio_base64"] = captureAudio();
  
  doc["anomaly_det"] = "normal";  // Simulating anomaly detection result
  doc["anomaly_bool"] = 0;  // No anomaly

  // Serialize to JSON
  char jsonBuffer[1024];
  serializeJson(doc, jsonBuffer); // Convert JSON object to string

  // Publish the message to AWS IoT topic
  if (client.publish(AWS_IOT_PUBLISH_TOPIC, jsonBuffer)) {
    Serial.println("Message published: ");
    Serial.println(jsonBuffer);
  } else {
    Serial.println("Message publishing failed");
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message received on topic: ");
  Serial.println(topic);

  // Handle the incoming message
  String message;
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  Serial.println("Payload: " + message);
}

void setup() {
  Serial.begin(115200);
  gpsSerial.begin(9600, SERIAL_8N1, 16, 17);  // Start GPS on UART2
  i2sInit();  // Initialize INMP441 microphone
  client.setCallback(callback);  // Set message callback function
  connectAWS();
}

void loop() {
  if (!client.connected()) {
    connectAWS();
  }
  client.loop();  // Keep the connection alive
  publishMessage();
  delay(5000);  // Publish a message every 5 seconds
}

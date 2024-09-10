#include "secrets.h"
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include "WiFi.h"
#include <ArduinoJson.h>
#include <Wire.h>
#include <HardwareSerial.h>
#include <TinyGPS++.h>
#include <driver/i2s.h>

#define AWS_IOT_PUBLISH_TOPIC   "esp32/pub"
#define AWS_IOT_SUBSCRIBE_TOPIC "esp32/sub"

#define I2S_WS 15
#define I2S_SD 13
#define I2S_SCK 14

TinyGPSPlus gps;
HardwareSerial gpsSerial(2);

WiFiClientSecure net;
PubSubClient client(net);

void i2sInit() {
  i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
    .sample_rate = 16000,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
    .communication_format = I2S_COMM_FORMAT_I2S,
    .intr_alloc_flags = 0,
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

String getGPSCoordinates() {
  String gpsData = "";
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
  }

  if (gps.location.isValid()) {
    gpsData = String(gps.location.lat(), 6) + "," + String(gps.location.lng(), 6);
  } else {
    gpsData = "0.000000,0.000000";
  }

  return gpsData;
}

String captureAudio() {
  size_t bytesRead;
  int16_t audioBuffer[1024];
  i2s_read(I2S_NUM_0, &audioBuffer, sizeof(audioBuffer), &bytesRead, portMAX_DELAY);
  return "dummy_audio_base64_string";
}

void connectAWS() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  net.setCACert(AWS_CERT_CA);
  net.setCertificate(AWS_CERT_CRT);
  net.setPrivateKey(AWS_CERT_PRIVATE);
  client.setServer(AWS_IOT_ENDPOINT, 8883);

  while (!client.connected()) {
    if (client.connect(THINGNAME)) {
      client.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);
    } else {
      delay(5000);
    }
  }
}

void publishMessage() {
  StaticJsonDocument<1024> doc;
  doc["device_id"] = millis();

  String gpsData = getGPSCoordinates();
  int commaIndex = gpsData.indexOf(',');
  String gpsLat = gpsData.substring(0, commaIndex);
  String gpsLon = gpsData.substring(commaIndex + 1);

  doc["GPS_lat"] = gpsLat;
  doc["GPS_lon"] = gpsLon;
  doc["audio_base64"] = captureAudio();
  doc["anomaly_det"] = "normal";
  doc["anomaly_bool"] = 0;

  char jsonBuffer[1024];
  serializeJson(doc, jsonBuffer);

  client.publish(AWS_IOT_PUBLISH_TOPIC, jsonBuffer);
}

void callback(char* topic, byte* payload, unsigned int length) {
  String message;
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
}

void setup() {
  Serial.begin(115200);
  gpsSerial.begin(9600, SERIAL_8N1, 16, 17);
  i2sInit();
  client.setCallback(callback);
  connectAWS();
}

void loop() {
  if (!client.connected()) {
    connectAWS();
  }
  client.loop();
  publishMessage();
  delay(5000);
}

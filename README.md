# Railway Track Defect Detection System (SIH 1584)

Welcome to the **Dual Cross-Verifying Geo-Marking System** for railway track defect detection. This advanced system integrates both microphone-based and ultrasonic transmitter-receiver setups to provide robust and accurate monitoring.

## Key Components

### 1. Detection & Data Collection
- **Audio Signals**: Captures and clips audio into 5-second files.
- **GPS Coordinates**: Associates GPS data with audio files.
- **Data Transmission**: Sends data to the cloud using an IoT device.

### 2. Data Storage
- **Base64 Encoding**: Encodes audio files and stores them securely in DynamoDB.

### 3. AI Processing
- **Data Retrieval**: Retrieves data from DynamoDB to AWS Elastic Beanstalk.
- **Feature Extraction**: Extracts MFCC features.
- **Algorithm**: Analyzes data using a Logistic Regression and Random Forest pipeline.

### 4. Anomaly Detection
- **Defects Detected**: Identifies wear, cracks, and burnt wheels.
- **Geo-tagging**: Marks anomalies with GPS coordinates and stores them in a secondary database.

### 5. Visualization
- **Dynamic Map**: Displays geo-tagged anomalies in real-time on an integrated geomap.

## System Highlights
- **Cross-Verification**: Enhances accuracy with combined microphone and ultrasonic data.
- **Data Transmission**: Ensures redundancy with GPS modules, Raspberry Pi, and cloud servers.
- **Automatic Detection**: Uses AI models to detect and geo-tag defects.
- **Secure Access**: Provides encrypted data for secure access by maintenance crews.

## Team Details

**Team Name:** TEAM_Topcoders

**Team Leader:** [@ownriver](https://github.com/ownriver)

**Team Members:**
- **Amaan Aijaz** - [@ownriver](https://github.com/ownriver) (2023UCS1582)
- **Rishav Shah** - [@rishavafk](https://github.com/rishavafk) (2023UCS1543)
- **Khushi Monga** - [@Khushi-monga](https://github.com/Khushi-monga) (2023UEC2584)
- **Ujjawal Kumar** - [@UJJAWALX42](https://github.com/UJJAWALX42) (2023UCS1502)
- **Ajisth Shukla** - [@shuklaafk](https://github.com/shuklaafk) (2023UCD2156)
- **Mohammad Bilal** - [@mohammadBilal03](https://github.com/mohammadBilal03) (2023UCS1638)

## Project Links

- **SIH Presentation**: [View the PPT](https://github.com/ownriver/SIH_INTERNAL_ROUND_2_Topcoders/blob/main/SIH_PPT_Topcoders.pdf)
- **Video Demonstration**: [SIH_1584_demo_video](https://www.youtube.com/watch?v=EWoAHoAi5wI)
- **3D CAD Models**: [Acoustic Mic System](https://www.tinkercad.com/things/2UOgYSBc0pL-acoustic-mic-aux-mic-geo-tracking-defect-detection-system?sharecode=t7Cl9CB0puufQ7OUfeHj0PJhTP1noBdmY2DmjV8xogA)             
                     [Ultrasonic Transmitter-Receiver System](https://www.tinkercad.com/things/jlbW1u8U0sm-ultrasonic-transmitter-receiver-defect-detection-verifying-syst?sharecode=IHqeQRYft3Sh_H7vds6x2g0W31OGxgIXeP10PK3jnBs)
- **Source Code:** [GitHub Repository](https://github.com/mohammadBilal03/SIH_INTERNAL_ROUND_2_TopCoder)
- **Additional Resources**: [Link TBD]

## How to Run Locally

1. **Backend**: Run `npm run start` to host the backend locally at port 5000.
2. **Frontend**: Run `npm run dev` to host the frontend locally at port 5173.

cat <<EOL >> README.md

# Running the Project Locally

# Running the Project Locally

1. **Clone the Repository**

   ```bash
   git clone https://github.com/mohammadBilal03/SIH_INTERNAL_ROUND_2_TopCoder.git
   cd SIH_INTERNAL_ROUND_2_TopCoder

2. **Install Dependencies**

   '''bash
   npm install

3. **RUN THE PROJECT**

   '''bash
   npm run start
   npm run dev
   






# Railway Track Defect Detection System (SIH 1584)

**Dual Cross-Verifying Geo-Marking System** for railway track defect detection. This advanced system integrates both microphone-based and ultrasonic transmitter-receiver setups to provide robust and accurate monitoring. The data is used by the AI model that is integrated to the Cloud server and thereby automatically detects and geo-marks the defects detected. The defect data is encrypted for better security and can only be accessed by select individuals. 

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
-----------------------------------------------------------------------------------------
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
----------------------------------------------------------------
## Project Links

- **SIH Presentation**: [View the PPT](https://github.com/ownriver/SIH_INTERNAL_ROUND_2_Topcoders/blob/main/SIH_PPT_Topcoders.pdf)
- **Video Demonstration**: [SIH_1584_demo_video](https://www.youtube.com/watch?v=EWoAHoAi5wI)
- **3D CAD Models**: [Acoustic Mic System](https://www.tinkercad.com/things/2UOgYSBc0pL-acoustic-mic-aux-mic-geo-tracking-defect-detection-system?sharecode=t7Cl9CB0puufQ7OUfeHj0PJhTP1noBdmY2DmjV8xogA)             
                     [Ultrasonic Transmitter-Receiver System](https://www.tinkercad.com/things/jlbW1u8U0sm-ultrasonic-transmitter-receiver-defect-detection-verifying-syst?sharecode=IHqeQRYft3Sh_H7vds6x2g0W31OGxgIXeP10PK3jnBs)
- **Source Code:** [GitHub Repository](https://github.com/mohammadBilal03/SIH_INTERNAL_ROUND_2_TopCoder)
- **Additional Resources**: [Research Paper](https://www.researchgate.net/publication/354632818_A_Novel_Approach_to_Railway_Track_Faults_Detection_Using_Acoustic_Analysis)
-----------------------------------------------------------------


## Running the Project Locally

1. **Clone the Repository**

   ```bash
   git clone https://github.com/mohammadBilal03/SIH_INTERNAL_ROUND_2_TopCoder.git
   cd SIH_INTERNAL_ROUND_2_TopCoder

2. **Install Dependencies**

    ```bash
   npm install

3. **RUN THE PROJECT**
    ```bash
   npm run dev
    npm run start

 **Backend**: Run `npm run start` to host the backend locally at port 5000.
 
 **Frontend**: Run `npm run dev` to host the frontend locally at port 5173.

 ----------------------------------------------------------------------------------------------------------------------------------------------------

 ## Tech Stacks and Technologies used:

 **SOFTWARE:**

- Application Development:
React Native Framework with HTML, CSS & JavaScript
Android Studio for Emulator

- Website Development:
Vite JS and React framework (frontend).
Express (Node.js web application framework) (backend).

- Machine Learning Frameworks:
Logistic regression
Librosa library
Random forest
Decision tree
AWS Elastic Beanstalk
Flask (for deployment)

- Cloud Services:
AWS IOT Core
AWS Lambda
AWS SNS
AWS Dynamo DB
AWS Cloud services

**HARDWARE:**

Raspberry Pi 5
INMP 441
NEO 6M module (GPS)
Ultrasonic Transmitter & Receiver
NC Mic (Shure SM7B)
Defect Detecting mic (Sennheiser MKE 600)


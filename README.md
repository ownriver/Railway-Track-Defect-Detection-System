# **Railway Track Defect Detection System** (SIH 1584)

We have developed an advanced **Dual Cross-Verifying Geo-Marking System** for detecting railway track defects. This system leverages both a microphone-based setup and an ultrasonic transmitter-receiver system for robust and accurate monitoring. 

## **Key Components:**

### **1. Detection & Data Collection**
   - The system detects audio frequencies and GPS coordinates, clips them into 5-second audio files, and sends the data to the cloud using an IoT device.

### **2. Data Storage**
   - Audio files are converted to Base64 format and securely stored in a DynamoDB database.

### **3. AI Processing**
   - Data is retrieved from DynamoDB and processed through an AI algorithm hosted on AWS Elastic Beanstalk. The algorithm extracts MFCC features and utilizes a Logistic Regression and Random Forest pipeline for analysis.

### **4. Anomaly Detection**
   - The system identifies anomalies such as wear, cracks, and burnt wheels. Detected anomalies are geo-tagged with GPS coordinates and stored in a secondary database for further action.

### **5. Visualization**
   - The website dynamically retrieves the geo-tagged anomaly data and displays it on an integrated geomap, providing a real-time view of the track's condition.

## 🚄 **System Highlights:**

- **🛠️ Dual Cross-Verification**: Combines microphone and ultrasonic data for enhanced accuracy.
- **📡 Data Transmission**: The collected data is transmitted to a GPS module, Raspberry Pi, and a storage system for redundancy before being uploaded to cloud servers.
- **🤖 Automatic Defect Detection**: Cloud-hosted AI models automatically detect defects and mark them using precise GPS coordinates (latitude and longitude).
- **🔒 Secure Access**: The website and application used by maintenance crews feature encrypted data for enhanced security.

---

This comprehensive system ensures that railway track defects are detected promptly and accurately, enhancing safety and efficiency in track maintenance operations.

---

This README provides an overview of the project, including team details, relevant links, tasks completed, tech stack, key features, and steps to run the project locally.


## 👥 Team Details

**Team Name:** TEAM_Topcoders  
**Team Leader:** [@ownriver](https://github.com/ownriver)

### 🏅 Team Members:

- **Amaan Aijaz** (2023UCS1582) - [@ownriver](https://github.com/ownriver)
- **Rishav Shah** (2023UCS1543) - [@rishavafk](https://github.com/rishavafk)
- **Khushi Monga** (2023UEC2584) - [@Khushi-monga](https://github.com/Khushi-monga)
- **Ujjawal Kumar** (2023UCS1502) - [@UJJAWALX42](https://github.com/UJJAWALX42)
- **Ajisth Shukla** (2023UCD2156) - [@shuklaafk](https://github.com/shuklaafk)
- **Mohammad Bilal** (2023UCS1638) - [@mohammadBilal03](https://github.com/mohammadBilal03)

---


## Project Links

- **SIH presentation**:
- **Video demonstration**:
- **3D CAD models** (for both constructions):
- **Source Code:** [GitHub Repository](https://github.com/mohammadBilal03/SIH_INTERNAL_ROUND_2_TopCoder)
- **Additional Resources**:


---------------------------------------------------------------------------------------------------------------------------------------------------------------
 
  **How to run locally?**

Run in the terminal (npm run start) to host backend locally at port 5000.

Run in the terminal (npm run dev) to host frontend locally at port 5173.

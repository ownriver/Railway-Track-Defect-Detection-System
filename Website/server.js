// // index.js
// import express from 'express';
// // import cors from 'cors';

// // // Enable CORS to allow communication between front-end and back-end
// // app.use(cors());

// const app = express();
// // const PORT = 5000;


// // app.get('/api/sensor-data', (req, res) => {
// //   const sensorData = [
// //     { trackSection: 'A', distance: 100, quality: 'Good', defect: false },
// //     { trackSection: 'B', distance: 200, quality: 'Worn', defect: true },
// //     { trackSection: 'C', distance: 300, quality: 'Fair', defect: false },
// //     { trackSection: 'D', distance: 400, quality: 'Critical', defect: true },
// //   ];

// //   res.json(sensorData);
// // });

// // app.listen(PORT, () => {
// //   console.log(`Server is running on port ${PORT}`);
// // });



// const port = 5000;

// // Simulated train position data
// const trainPosition = {
//   trainLat: 40.7128, // Example latitude
//   trainLon: -74.0060, // Example longitude
// };

// // Endpoint to get sensor data
// app.get('/api/sensor-data', (req, res) => {
//   // Simulate some sensor data
//   const sensorData = [
//     { trackSection: 1, distance: 100, quality: 'Good', defect: false },
//     { trackSection: 2, distance: 200, quality: 'Fair', defect: true },
//     { trackSection: 3, distance: 300, quality: 'Poor', defect: false },
//   ];
//   res.json(sensorData);
// });

// // Endpoint to get train position
// app.get('/api/train-position', (req, res) => {
//   res.json(trainPosition);
// });

// // Start the server
// app.listen(port, () => {
//   console.log(`Server running at http://localhost:${port}`);
// });








// server.js
// import express from 'express';
// import AWS from 'aws-sdk';
// import cors from 'cors';
// const app = express();
// const port = 5000;

// // Enable CORS for frontend requests
// app.use(cors());

// // Configure AWS SDK for DynamoDB
// AWS.config.update({
//   region: 'ap-south-1', // e.g., 'us-east-1'
//   accessKeyId: 'AKIAYSE4NUMSTXCZLGHS', // Replace with your access key
//   secretAccessKey: '9uRpEh2yFwsnW9IjJCRZp/y69D5cJfoWxCo5SO9D' // Replace with your secret key
// });

// // DynamoDB instance
// const dynamoDB = new AWS.DynamoDB.DocumentClient();

// // DynamoDB Table name
// const tableName = 'Final_data';

// // Fetch train positions and defects from DynamoDB
// app.get('/api/train-data', async (req, res) => {
//   try {
//     const params = {
//       TableName: tableName,
//     };

//     // Scan DynamoDB to get all items (train position, anomalies, defects)
//     const data = await dynamoDB.scan(params).promise();
    
//     // Send the response back to the frontend
//     res.json(data.Items);
//   } catch (error) {
//     console.error('Error fetching data from DynamoDB:', error);
//     res.status(500).json({ error: 'Failed to fetch train data' });
//   }
// });

// // Start server
// app.listen(port, () => {
//   console.log(`Server running on port ${port}`);
// });






// server.js
import express from 'express';
import cors from 'cors';
import { DynamoDBClient, ScanCommand } from '@aws-sdk/client-dynamodb';

const app = express();
const port = 5000;

// Enable CORS for frontend requests
app.use(cors());

// AWS SDK v3 DynamoDB client setup
const dynamoDBClient = new DynamoDBClient({
  region: 'ap-south-1', // e.g., 'us-east-1'
  credentials: {
    accessKeyId: 'AKIAYSE4NUMSTXCZLGHS',    // Add your AWS Access Key ID
    secretAccessKey: '9uRpEh2yFwsnW9IjJCRZp/y69D5cJfoWxCo5SO9D',  // Add your AWS Secret Access Key
  }
});

// Define the table name
const tableName = 'Final_data';

// API endpoint to fetch train positions and defects from DynamoDB
app.get('/api/train-data', async (req, res) => {
  try {
    const params = {
      TableName: tableName,
    };

    const command = new ScanCommand(params);
    const data = await dynamoDBClient.send(command);

    // Send the fetched items (train positions and defects) as a JSON response
    res.json(data.Items);
  } catch (error) {
    console.error('Error fetching data from DynamoDB:', error);
    res.status(500).json({ error: 'Failed to fetch train data' });
  }
});

// Start the Express server
app.listen(port, () => {
  console.log(`Server running on http://localhost:${port}`);
});

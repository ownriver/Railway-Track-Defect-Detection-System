// import React, { useState, useEffect } from "react";
// import './App.css';

// function App() {
//   const [sensorData, setSensorData] = useState([]);
//   const [loading, setLoading] = useState(true);
//   const [error, setError] = useState(null);

//   // Fetch the sensor data from the back end
//   useEffect(() => {
//     fetch('http://localhost:5000/api/sensor-data')
//       .then((response) => {
//         if (!response.ok) {
//           throw new Error('Network response was not ok');
//         }
//         return response.json();
//       })
//       .then((data) => {
//         setSensorData(data);
//         setLoading(false);
//       })
//       .catch((error) => {
//         console.error('Error fetching sensor data:', error);
//         setError('Failed to fetch sensor data.');
//         setLoading(false);
//       });
//   }, []);

//   if (loading) return <div>Loading sensor data...</div>;
//   if (error) return <div>{error}</div>;

//   return (
//     <div className="App">
//       <h1>Rail Defect Detection System</h1>
//       <div className="data-list">
//         {sensorData.map((data, index) => (
//           <div key={index} className={`data-item ${data.defect ? 'defect' : 'normal'}`}>
//             <p>Track Section: {data.trackSection}</p>
//             <p>Distance from Central Point: {data.distance} meters</p>
//             <p>Quality: {data.quality}</p>
//             <p>Status: {data.defect ? 'Defect Detected' : 'Normal'}</p>
//           </div>
//         ))}
//       </div>
//     </div>
//   );
// }

// export default App;





// // src/App.jsx
// import { useState, useEffect } from 'react';
// import './App.css';
// import { MapContainer, TileLayer, Marker, Popup } from 'react-leaflet';
// import L from 'leaflet';
// import 'leaflet/dist/leaflet.css';

// function App() {
//   const [trainData, setTrainData] = useState([]);
//   const [loading, setLoading] = useState(true);
//   const [error, setError] = useState(null);

//   // Custom icons for train and defects
//   const trainIcon = new L.Icon({
//     iconUrl: 'https://example.com/train-icon.png',
//     iconSize: [32, 32],
//   });

//   const defectIcon = new L.Icon({
//     iconUrl: 'https://example.com/defect-icon.png',
//     iconSize: [32, 32],
//   });

//   // Fetch train data and anomalies from the backend
//   useEffect(() => {
//     fetch('http://localhost:5000/api/train-data')
//       .then((response) => response.json())
//       .then((data) => {
//         setTrainData(data);
//         setLoading(false);
//       })
//       .catch((err) => {
//         setError(err.message);
//         setLoading(false);
//       });
//   }, []);

//   if (loading) return <div>Loading train data...</div>;
//   if (error) return <div>Error: {error}</div>;

//   return (
//     <div className="App">
//       <h1>Rail Defect Detection System</h1>

//       <MapContainer center={[40.7128, -74.0060]} zoom={13} style={{ height: '400px', width: '100%' }}>
//         <TileLayer
//           url="https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png"
//           attribution='&copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors'
//         />

//         {/* Display train locations */}
//         {trainData.map((train) => (
//           <Marker key={train.trainId} position={[train.trainLat, train.trainLon]} icon={trainIcon}>
//             <Popup>
//               <strong>Train ID: </strong>{train.trainId}<br />
//               <strong>Lat: </strong>{train.trainLat}<br />
//               <strong>Lon: </strong>{train.trainLon}
//             </Popup>
//           </Marker>
//         ))}

//         {/* Display defects as markers */}
//         {trainData.map((train) =>
//           train.defects.map((defect) => (
//             <Marker key={defect.defectId} position={[defect.lat, defect.lon]} icon={defectIcon}>
//               <Popup>
//                 <strong>Defect ID: </strong>{defect.defectId}<br />
//                 <strong>Severity: </strong>{defect.severity}<br />
//                 <strong>Lat: </strong>{defect.lat}<br />
//                 <strong>Lon: </strong>{defect.lon}
//               </Popup>
//             </Marker>
//           ))
//         )}
//       </MapContainer>
//     </div>
//   );
// }

// export default App;

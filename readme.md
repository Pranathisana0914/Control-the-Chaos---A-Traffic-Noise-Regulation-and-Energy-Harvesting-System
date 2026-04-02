# 🚦 Control the Chaos: Traffic Noise Regulation & Energy Harvesting System

## 📌 Overview
This project is a smart traffic management system designed to regulate noise pollution and improve traffic efficiency. It integrates real-time sound monitoring, intelligent traffic control, and ambulance detection using frequency analysis. The system also explores energy harvesting for sustainable operation.

---

## ⚙️ Technologies Used
- Arduino
- Processing (GUI)
- Serial Communication
- FFT (Fast Fourier Transform)
- Embedded Systems

---

## 🔧 System Components
- Sound Sensor Module
- Arduino Microcontroller
- LEDs (Traffic Signals)
- Microphone (for GUI input)
- Processing Software

---

## 🔌 Arduino Code
The Arduino acts as the core controller of the system. It reads sound sensor data, controls traffic signals, and communicates with the GUI.

**Functions:**
- Monitors noise levels
- Controls traffic lights (R/Y/G)
- Sends data (signal, timer, dB, penalty)
- Receives ambulance detection signal

---

## 🖥️ Processing GUI & Detection
The GUI performs real-time audio processing using FFT to detect ambulance sirens (700–1500 Hz range).

**Functions:**
- Displays traffic signals, timer, and noise level
- Shows penalty alerts
- Visualizes frequency spectrum
- Sends ambulance priority signal to Arduino

---

## 📸 Simulation Results
![Result1](output1.png)
![Result2](output2.png)


---

## Circuit diagram
![Result2](output3.png)

---

##Block diagram
![Result2](output4.png)

## 🎥 Demo Video
(Add your YouTube link here)

---

## 🚀 Features
- Real-time noise monitoring
- Smart traffic signal control
- Ambulance detection using FFT
- Automatic traffic prioritization
- Penalty system for high noise
- Live GUI visualization

---

## 👩‍💻 Author
Pranathi

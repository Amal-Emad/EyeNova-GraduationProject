# EYE_NOVA عون : Traffic Light Detection System: Empowering Color-Blind Individuals with Real-Time Assistance

![traffic-lights-color-blindness](https://github.com/user-attachments/assets/5b854095-21d0-4773-a375-68f76979fb2e)

## Overview
The **Traffic Light Detection System** is a real-time solution designed to assist color-blind individuals by accurately detecting and displaying traffic light states. Leveraging computer vision and edge AI technologies, this system ensures accessibility and safety for users navigating traffic environments. 

The system is built around the **ESP32-CAM module**, powered by the **Edge Impulse platform**, and utilizes the **FOMO (Faster Objects, More Objects)** algorithm for lightweight object detection.

---

## Core Components

### 1. ESP32-CAM Module
- A low-cost microcontroller with integrated Wi-Fi and a camera module.
- Captures real-time images of traffic lights for processing.
- Optimized for edge computing with limited resources.
  
<img src="https://github.com/user-attachments/assets/fb380c29-20a1-49a3-8245-810d10fea7bd" alt="ESP32-CAM Module" width="300" height="350">

## 2. Edge Impulse Platform
- Used for training and deploying machine learning models.
- Implements the FOMO algorithm for efficient object detection on resource-constrained devices.

### 3. OLED Display
- Provides visual feedback to users by displaying the detected traffic light state.
- Ensures accessibility for color-blind individuals through textual or symbolic representations.
<img src="https://github.com/user-attachments/assets/4f84f38a-9fa7-4e0f-bb26-75921b70f470" alt="OLED Display" width="300" height="330">

### 4. FTDI Module
- Facilitates programming and debugging of the ESP32-CAM.
- Provides a USB-to-serial interface for communication.
  



## System Connection Diagram
Below is the connection diagram for the ESP32-CAM, OLED Display, and FTDI Module:

### Connection Details:
#### ESP32-CAM GPIO Pins:
- **TX → FTDI RX**  
- **RX → FTDI TX**  
- **GND → FTDI GND**  
- **5V → FTDI VCC**

#### OLED Display Pins:
- **SDA → ESP32-CAM GPIO 14**  
- **SCL → ESP32-CAM GPIO 15**  
- **VCC → 3.3V**  
- **GND → GND**

<img src="https://github.com/user-attachments/assets/eadb4898-792d-40c1-a8ed-cc80ae2d672e" alt="Circuit Diagram" width="400" height="300"> 

----------------------------------------------------------------------------------------------------------------

## Edge Impulse Workflow

### 1. Data Collection and Preprocessing
- **Dataset Source:** Obtained from Roboflow in YOLOv5 format with pre-labeled images and a YAML file.
- **Dataset Details:**  
  - Total images: **2,627**  
  - Labels: **Red Traffic Light**, **Yellow Traffic Light**, **Green Traffic Light**.

#### Dataset Example:

<img src="https://github.com/user-attachments/assets/f66326a2-8cfc-4b24-b4e4-00b6cdd42cee" alt="Dataset Example" width="400" height="300"> 

### 2. Data Splitting
- Split the dataset into **80% training** and **20% testing** sets.


### 3. Feature Generation
- **Input Details:**
  - Image size: **96x96 pixels**.
  - Input format: **Grayscale or RGB**.
- **Feature Extraction Process:**
  - Converts images into feature vectors for training.
  - **Time:** ~15 ms per sample.  
  - **Memory usage:** ~4 KB per sample.

<img src="https://github.com/user-attachments/assets/95f739bb-d58b-4292-a52e-5d044e96c954" alt="Feature Generation" width="400" height="300"> 


### 4. Model Training
- **Model Type:** FOMO neural network architecture.
- **Training Details:**
  - Input dimensions: **96x96 pixels**.
  - Output dimensions: **3 classes (Red, Yellow, Green)**.
  - Training process: Iterative optimization of neural network weights.

#### Model Training:

<img src="https://github.com/user-attachments/assets/bd7c5a22-e8ce-4fcc-b557-d6035000ffb8" alt="Create Impulse" width="400" height="300"> <img src="https://github.com/user-attachments/assets/570adee0-1f53-412a-bfb3-657506e72deb" alt="Training Settings" width="400" height="500"> 


## Performance Metrics

### Confusion Matrix Analysis
- **Background:**  
  100% of background samples were correctly classified.  
- **Traffic-Green:**  
  - 88.7% correctly identified.  
  - 11.3% misclassified as Traffic-Red.  
- **Traffic-Red:**  
  - 83.9% correctly identified.  
  - 16.1% misclassified as Traffic-Green.  
- **Traffic-Yellow:**  
  - 92.8% correctly identified.  
  - 7.2% misclassified as Background.
### Key Metrics
- **Precision (Non-Background):** 0.87  
- **Recall (Non-Background):** 0.88  
- **F1 Score (Non-Background):** 0.88  


<img src="https://github.com/user-attachments/assets/7e0f3e82-4d41-4e16-b480-f8769cb0ff82" alt="Training Output" width="400" height="300"> 

----------------------------------------------------------------------------------------------------------------
#### Try The Model

![trymodel](https://github.com/user-attachments/assets/df091973-7c34-4003-bb05-f17645915bde)

### 5. Model Deployment
- Export the trained model as an **Arduino library**.
- Deploy the model to the ESP32-CAM using the **Edge Impulse CLI**.

#### Model Deployment:

<img src="https://github.com/user-attachments/assets/1d843b9a-c436-422c-88f4-3b9ff01eb39e" alt="Include Traffic Library" width="400" height="300"> <img src="https://github.com/user-attachments/assets/5d9dc3d8-c72a-4c8f-be83-9f49bf5c4c50" alt="Select Edge Impulse Zip Library" width="400" height="300"> 

----------------------------------------------------------------------------------------------------------------


## Demonstration
### Final System in Action
The **Traffic Light Detection System** is housed in a compact and portable setup, with the ESP32-CAM capturing real-time images and the OLED display providing immediate feedback.

<img src="https://github.com/user-attachments/assets/e21e641e-58d7-4e87-ad01-84d04ffe5236" alt="Final Look of Smart Glass" width="500" height="600">

#### How It Works:
1. The **ESP32-CAM** RealTime Detection.
2. The **FOMO model** processes the Frames and detects the traffic light state.
3. The detected state is displayed on the **OLED screen** in text format (e.g., "Red Light Detected").
4. The system continuously updates the display in real time.

---
### About FOMO

The FOMO (Faster Objects, More Objects) model is a highly efficient object detection algorithm designed for resource-constrained devices.
Key Features of FOMO:

   #### Lightweight Architecture: Built on MobileNet, making it ideal for edge AI devices.
   #### High-Speed Detection: Processes images in real-time (~15ms per frame).
   #### TensorFlow Lite Compatibility: Allows easy deployment on microcontrollers like ESP32-CAM.

FOMO uses grid-based detection, ensuring that even small objects, such as traffic lights, are detected accurately.


### References

   #### Edge Impulse Platform: https://www.edgeimpulse.com
   #### ESP32-CAM Documentation: https://docs.espressif.com
   #### FOMO Model Overview: https://www.edgeimpulse.com/blog/introducing-fomo

![car-crash-accident](https://github.com/user-attachments/assets/2563d8f6-e0c7-460b-888c-c835526c0997)

    
### Summary
The **Traffic Light Detection System** leverages the ESP32-CAM and Edge Impulse platform to provide a real-time, efficient, and accurate solution for detecting traffic light states. By utilizing the **FOMO algorithm**, the system ensures accessibility for color-blind individuals, enhancing their safety and independence in traffic environments.

# **Traffic Light Detection Project**

## **Overview**
The **Traffic Light Detection Project** utilizes an **ESP32-CAM** and **Edge Impulse** to detect traffic lights in real-time. The project incorporates machine learning for object detection and includes features such as a buzzer alert system and an OLED display for visual feedback.

---

## **Features**
- **Real-time traffic light detection** using a machine learning model.
- **OLED display** for displaying detection results.
- **Buzzer alert system** to signal when a traffic light is detected.
- **Efficient image processing** powered by Edge Impulse SDK.
- **ESP32-CAM integration** for image capture.

---

## **Hardware Requirements**
- **ESP32-CAM (AI-Thinker Model)**
- **Buzzer**
- **OLED Display (128x64 resolution)**
- **Connecting Wires**
- **Micro-USB Cable**
- **Power Supply for ESP32-CAM**

---

## **Software Requirements**
- **Arduino IDE** (for code deployment)
- **Edge Impulse Studio** (for training and exporting the ML model)
- **Edge Impulse SDK** (for model inference)
- **Adafruit SSD1306 Library** (for OLED display)

---

## **Setup Instructions**

### **1. Hardware Connections**
- **ESP32-CAM**:
  - Connect the camera pins based on the provided pin configuration in the code.
- **Buzzer**:
  - Connect the buzzer's positive pin to **GPIO 13** and the negative pin to **GND**.
- **OLED Display**:
  - Connect **SDA** to GPIO 15 and **SCL** to GPIO 14.

### **2. Software Configuration**
1. **Clone this repository**:
   ```bash
   git clone https://github.com/your-repo/traffic-light-detection
   cd traffic-light-detection

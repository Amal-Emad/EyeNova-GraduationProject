# Smart Glove System

The **Smart Glove System** is an innovative assistive device designed to enable seamless communication for individuals with hearing or speech impairments. By translating hand gestures into audible speech, it empowers users to interact more effectively in everyday scenarios. The system uses a combination of flex sensors, an Arduino Uno, and a DFPlayer Mini module to provide real-time gesture recognition and audio feedback.

![Deaf-Awareness-Week--1200x834](https://github.com/user-attachments/assets/53533468-5962-4197-a5f5-683c9fb97bd2)

---

## Vision and Goals

### Vision:

To bridge the communication gap for individuals with hearing or speech impairments through affordable and user-friendly technology.

### Goals:

- Enable real-time translation of gestures into audible speech.
- Provide a compact, wearable solution that is simple to use and maintain.
- Lay the groundwork for more advanced gesture recognition systems in the future.

---

## Key Features

- **Gesture-to-Speech Conversion**: Recognizes specific hand gestures and translates them into pre-recorded speech.
- **Compact Design**: Built using lightweight and easily wearable components.
- **Customizable**: Audio files can be updated to support different languages or user-specific needs.
- **Real-Time Feedback**: Immediate audio output enhances the communication experience.

---

## Hardware Components

### 1. **Flex Sensors**

- Measure the bending of fingers using changes in resistance.
- Connected to the Arduino’s analog pins (A0-A4).
- Resistors (10kΩ) ensure accurate voltage division and sensor stabilization.

<img src="https://github.com/user-attachments/assets/d68f6728-32b3-4472-8807-f8993c1d4c76" alt="Flex Sensors" width="300" height="200"> 

### 2. **Arduino nano**

- Serves as the central microcontroller for reading sensor data and controlling the audio module.
- Processes sensor input and maps it to specific gestures.

### 3. **DFPlayer Mini**

- Plays pre-recorded audio files from an SD card.
- Controlled by the Arduino via serial communication.
- Outputs sound to a connected speaker.
  
<img src="https://github.com/user-attachments/assets/ef0f2bb9-e8a8-4af7-82f4-6dbede077bb7" alt="DFPlayer Mini" width="300" height="200"> 

### 4. **Speaker**

- Outputs audio feedback for detected gestures.

<img src="https://github.com/user-attachments/assets/5851a3cb-c425-4ec0-b098-cf50d0de2e37" alt="Speaker" width="300" height="200"> 

### 5. **SD Card**

- Stores pre-recorded audio files in a format compatible with the DFPlayer Mini (e.g., MP3).

### 6. **Power Supply**

- Powered via USB connection to a computer or external 5V power source.

---

## System Architecture

### Workflow

1. **Input**: Flex sensors measure the bending of fingers and send analog signals to the Arduino.
2. **Processing**: The Arduino maps sensor inputs to predefined gestures using threshold values.
3. **Output**: The Arduino sends commands to the DFPlayer Mini to play the corresponding audio file.
4. **Feedback**: The speaker outputs the audio for the detected gesture.

---

## Hardware Wiring

### Flex Sensors

1. Connect flex sensors to analog pins A0–A4 on the Arduino Uno.
2. Use a 10kΩ resistor in a voltage divider configuration with each sensor.

### DFPlayer Mini

1. Connect the **RX pin** of the DFPlayer Mini to **Pin 3 (TX)** of the Arduino.
2. Connect the **TX pin** of the DFPlayer Mini to **Pin 2 (RX)** of the Arduino.
3. Connect the **SPK\_1** and **SPK\_2** pins to the speaker.
4. Power the module via the Arduino’s **5V** and **GND** pins.

### Power Supply

- Power the Arduino via USB or an external 5V power source.

---

## Software Implementation

The system is programmed using the Arduino IDE, leveraging libraries for serial communication and audio playback. The code processes flex sensor data, maps it to gestures, and triggers audio feedback through the DFPlayer Mini.

### Key Functionalities

1. **Gesture Detection**:
   - Reads analog values from flex sensors.
   - Maps sensor values to specific gestures using threshold logic.
2. **Audio Feedback**:
   - Sends commands to the DFPlayer Mini to play pre-recorded audio files.
3. **Debugging and Monitoring**:
   - Outputs sensor data and system state to the Serial Monitor for testing.

---

## Code Overview

### Initialization

- Sets up pins for flex sensors and serial communication.
- Initializes the DFPlayer Mini and configures volume levels.

### Gesture Mapping

- Defines threshold values for each flex sensor.
- Detects predefined gestures based on sensor readings.

### Audio Playback

- Triggers playback of specific audio files corresponding to detected gestures.

```cpp
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

const int flexPins[] = {A0, A1, A2, A3, A4};
const int threshold = 200;
SoftwareSerial mp3Serial(2, 3);
DFRobotDFPlayerMini player;

void setup() {
  Serial.begin(9600);
  mp3Serial.begin(9600);
  if (!player.begin(mp3Serial)) {
    Serial.println("DFPlayer Mini initialization failed!");
    while (true);
  }
  player.volume(20);
}

void loop() {
  for (int i = 0; i < 5; i++) {
    int flexValue = analogRead(flexPins[i]);
    if (flexValue > threshold) {
      Serial.print("Gesture detected: Finger ");
      Serial.println(i + 1);
      player.play(i + 1);
      delay(2000);
    }
  }
}
```

---

## Setup Instructions

### Hardware Setup

1. Assemble the components as per the wiring diagram.
2. Secure connections to prevent loose wiring.

### Software Setup

1. Install the Arduino IDE.
2. Add the `DFRobotDFPlayerMini` and `SoftwareSerial` libraries.
3. Upload the provided code to the Arduino Uno.

### Preparing the SD Card

1. Format the SD card as FAT32.
2. Add audio files named sequentially (e.g., `001.mp3`, `002.mp3`).

### Testing

1. Open the Serial Monitor to monitor sensor data.
2. Test gestures by bending fingers and verify audio output.


---

## Applications

- Assistive technology for individuals with hearing or speech impairments.
- Educational tools for teaching sign language.
- Potential use in robotics and human-computer interaction.

 ![photo_2025-01-07_23-32-43](https://github.com/user-attachments/assets/496514f0-3c62-4105-8408-6e0ed94d90d3)
 

---

## Future Enhancements

- Expand the gesture library to support more complex gestures.
- Integrate Bluetooth for wireless communication.
- Add text-to-speech functionality for dynamic speech generation.
- Develop a mobile app interface for customization and monitoring.



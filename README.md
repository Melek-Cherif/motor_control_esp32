# ESP32 Servo Motor Control Project

This project was created to help get familiar with programming the ESP32 using the ESP-IDF framework. The main file runs an example that controls a servo motor using Pulse Width Modulation (PWM). There is also an input from 4 IR sensors. Each sensor presents an angle for the motor movement.

## Project structure
main/ - Contains the main application code
components/ - Contains any additional components
CMakeLists.txt - CMake build script
sdkconfig - Configuration file for ESP-IDF

## Steps to Run the Code on ESP32 Using idf.py

1. **Build the project:**
   ```sh
   idf.py build
2. **flash to target:**
   ```sh
   idf.py build

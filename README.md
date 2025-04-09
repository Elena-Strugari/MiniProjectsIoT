# Mini Projects – Arduino IoT Collection

This repository includes a collection of beginner-to-intermediate level **Arduino IoT mini-projects**. Each project focuses on a specific sensor or automation concept using the Arduino platform. All projects include code (`.ino`) and circuit diagrams (`.png`) for quick implementation and simulation.

---

## Projects Overview

### 1. Bionic Arm Using Flex Sensor
- **File**: `bionic_arm_using_flex_sensor1.ino`
- **Diagram**: `Bionic Arm Using flex Sensor.png`
- **Description**: Reads values from a flex sensor to control servo motors, simulating a robotic/bionic arm.
- **Components**: Arduino Uno, Flex sensor, Servo motor, Jumper wires.
- **Use case**: Prosthetics simulation, gesture-controlled robotics.

---

### 2. Fire Alarm System (Temperature + Gas Sensor)
- **File**: `fire_alarm_system_temperature_and_gas_sensor.ino`
- **Diagram**: `Fire Alarm System Temperature and Gas Sensor.png`
- **Description**: Triggers an alarm if either gas levels or temperature exceed safe thresholds.
- **Components**: Arduino Uno, Gas sensor (MQ-series), Temperature sensor (e.g., LM35), Buzzer.
- **Use case**: Fire detection, safety systems for homes or labs.

---

### 3. LED Controller with Temperature and Brightness Adjustment
- **File**: `LED Controller with Temperature and Brightness Adjustment.ino`
- **Diagram**: `LED Controller with Temperature and Brightness Adjustment.png`
- **Description**: Adjusts LED brightness based on room light and temperature values.
- **Components**: Arduino Uno, LDR (light sensor), LM35 or DHT11 (temperature), LED.
- **Use case**: Smart lighting systems, ambient control.

---

### 4. Password Protected Security System
- **File**: `password_protected_security_system1.ino`
- **Diagram**: `Password Protected Security System.png`
- **Description**: A simple keypad-based password entry system for security access.
- **Components**: Arduino Uno, 4x4 Keypad, Servo motor or LED, Buzzer.
- **Use case**: Basic access control, school projects.

---

### 5. Smart Home Automation Using Sensors
- **File**: `smart_home_automation_using_sensors1.ino`
- **Diagram**: `Smart Home Automation Using Sensors.png`
- **Description**: Automates lights based on motion (PIR) and ambient light (LDR).
- **Components**: Arduino Uno, PIR Sensor, LDR, Relay module, Bulb (simulated).
- **Use case**: Room automation, energy-saving systems.

---

### 6. Ultrasonic Distance Sensor
- **File**: `Ultrasonic Sensor.ino`
- **Diagram**: `Ultrasonic Sensor.png`
- **Description**: Measures distance using the HC-SR04 sensor and displays it via Serial Monitor or LCD.
- **Components**: Arduino Uno, HC-SR04 sensor.
- **Use case**: Obstacle detection, smart parking, object counters.

---

## How to Run Each Project

1. Open the `.ino` file using **Arduino IDE**.
2. Connect the components as shown in the respective `.png` diagram.
3. Select the correct **Board** and **COM Port** in Arduino IDE.
4. Click **Upload**.
5. Open **Serial Monitor** (if needed) to view sensor readings.

---

## Prerequisites

- Arduino IDE installed.
- Basic understanding of electronics and Arduino boards.
- Sensors and components mentioned in each project.

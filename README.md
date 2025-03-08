# Firefighting Robot System

## Overview
The **Firefighting Robot System** is an autonomous robotic vehicle designed to detect and extinguish fires. It utilizes IR sensors for obstacle detection, a flame sensor for fire detection, and a servo-controlled water pump for firefighting. The system is powered by an L298N motor driver and operates using an Arduino microcontroller.

## Features
- **Fire Detection**: A flame sensor identifies the presence of fire and triggers the extinguishing mechanism.
- **Obstacle Avoidance**: Infrared (IR) sensors detect objects and help the robot navigate around obstacles.
- **Autonomous Navigation**: The robot makes real-time decisions based on sensor input.
- **Fire Extinguishing Mechanism**: A servo-controlled water pump activates when a fire is detected.
- **Alarm System**: A buzzer and LED alert users when a fire is detected.

## Hardware Components
### Microcontroller & Motor Driver:
- **Arduino (Uno/Nano/MEGA)**: Controls the system logic.
- **L298N Motor Driver**: Manages the movement of the motors.
- **Servo Motor**: Adjusts the water pump direction.

### Sensors:
- **IR Sensors (A0, A1, A2)**: Detect obstacles on the right, front, and left.
- **Flame Sensor (A3)**: Detects fire and triggers the extinguishing mechanism.
- **Buzzer & LED (Pins 3, 4)**: Alerts users when fire is detected.

### Actuators:
- **Motors (Pins 5-10)**: Drive the robot in different directions.
- **Water Pump (A5)**: Sprays water to extinguish fires.

## System Architecture
1. **Sensor Data Processing**
   - The IR sensors continuously monitor the surroundings.
   - The flame sensor detects fire and assesses its intensity.
2. **Decision-Making Algorithm**
   - If a fire is detected, the robot halts, activates the water pump, and triggers the alarm.
   - If an obstacle is detected, the robot navigates around it.
   - If no fire or obstacles are present, the robot continues moving forward.
3. **Fire Suppression Mechanism**
   - The servo motor adjusts the water pump’s direction.
   - The pump is activated to spray water on the fire.
   - The system deactivates the alarm when the fire is extinguished.

## Software Requirements
- **Arduino IDE**: Used to program the microcontroller.
- **C++ (Embedded Systems Programming)**: Main language for controlling hardware.
- **Servo & Motor Control Libraries**: Required for handling movement and fire suppression mechanisms.

## Installation & Usage
### Hardware Setup:
1. Assemble the components as per the wiring diagram.
2. Connect the Arduino to the motor driver and sensors.
3. Ensure a 12V power supply for efficient motor operation.

### Software Deployment:
1. Install the **Arduino IDE**.
2. Upload the provided code (`firefighting_robot.ino`) to the microcontroller.
3. Power on the system and monitor real-time data using the Serial Monitor.

## Future Enhancements
- **AI-based Fire Detection**: Implement computer vision for enhanced accuracy.
- **Remote Control Functionality**: Integrate IoT for remote monitoring and control.
- **Enhanced Navigation**: Utilize LiDAR or ultrasonic sensors for improved obstacle detection.
- **Multiple Fire Extinguishing Methods**: Introduce CO2-based extinguishing for electrical fires.

## Contributors
- **Developer:** Osama Tayseer Abualwafa
- **Supervisor:** Dr. Eid

---
This project aims to enhance fire safety by leveraging autonomous robotics and intelligent fire suppression techniques. 🚒🔥


# Linefollower Robotics Project

## Table of Contents
1. [Introduction](#introduction)  
2. [General Description](#general-description)  
3. [Hardware Design](#hardware-design)  
4. [Software Design](#software-design)  
5. [Results](#results)  
6. [Conclusions](#conclusions)  
7. [GitHub Repository Structure](#github-repository-structure)  
8. [Journal](#journal)  
9. [Bibliography](#bibliography)
10. [License](#license)


## Introduction  
- **What it does:** A robot designed to follow a black line on a white background.  
- **Purpose:** Inspired by my passion for cars, this project blends my interests in vehicles and robotics.  
- **Inspiration:** The concept draws from the functionality of RC cars.  
- **Why it’s useful:** It provides an engaging and interactive way to explore robotics while being fun to play with.  
- **Functionalities:** The project uses GPIO for motor control, ADC for sensor reading, PID control for line following, and serial debugging to monitor the robot's behavior.

---

## General Description  
<a>  
<img src="https://github.com/gabirelul/Linefollower-Robotics-Project/blob/main/images/scheme.jpg" width = "500px"></img>  
</a>

This block diagram illustrates the system architecture of the Linefollower

### 1. QTR-8 Sensor Array  
- **Connection**: Connected to analog pins 6-11 for line detection.  
- **Function**: The infrared sensors provide HIGH/LOW outputs depending on the surface reflectivity (black or white).  
- **Software Logic**: Sensor values are read using the ADC (Analog to Digital Converter), and the calibration process ensures accurate readings.

### 2. DC Motors  
- **Control**: Managed via GPIO pins through the Motor Shield.  
- **Pins**: The Motor Shield uses digital pins to control motor speed and direction.  
- **PID Control**: The robot adjusts the motor speeds based on the line position calculated using the PID control algorithm to maintain line following.

### 3. LCD 16x2 Display  
- **Connection**: Connected through an I2C module.  
- **Function**: Displays sensor readings, system data, and the status of the robot. The display updates in real-time, showing whether the robot is centered, left, or right of the line.

### 4. Potentiometer  
- **Connection**: Adjusts the LCD display contrast.  
- **Wiring**: Connected to 5V, GND, and an analog input pin to allow easy adjustments of the display contrast.

### 5. RGB LED  
- **Control**: The Red and Green pins are connected to separate digital pins for controlling brightness and color mixing.  
- **Software Control**: The LED can be programmed to indicate different statuses, such as "Line Lost" or "Line Followed."

### 6. Power Supply  
- **Battery**: The system is powered via a 9V battery connected to the Arduino’s barrel jack input.  
- **Motor Power**: The Motor Shield draws power directly from the 9V battery to drive the motors, ensuring sufficient power for both the motors and the sensors.

---

## Hardware Design  
<a>  
<img src="https://github.com/gabirelul/Linefollower-Robotics-Project/blob/main/images/thinker.png" width = "500px"></img>  
</a>

### Parts List
| Component                 | Quantity | Datasheet Link|
|---------------------------|----------|-------------------------------------------------------------------------------|
| LCD 16x2                  | 1        | [Datasheet](https://components101.com/sites/default/files/component_datasheet/16x2%20LCD%20Datasheet.pdf) |
| Breadboard                | 1        | [Datasheet](https://components101.com/sites/default/files/component_datasheet/Breadboard%20Datasheet.pdf) |
| DC Motors                 | 2        | [Datasheet](https://www.pololu.com/file/download/motor-datasheet.pdf) |
| Wheels                    | 2        | N/A |
| Jumper Cables             | 20+      | [Datasheet](https://www.cedist.com/sites/default/files/associated_files/s-w604_spec.pdf)|
| 9V Battery                | 1        | N/A |
| Battery Connector for 9V  | 1        | N/A |
| Potentiometer             | 1        | [Datasheet](https://components101.com/sites/default/files/component_datasheet/potentiometer%20datasheet.pdf)|
| QTR-8 Sensor              | 1        | [Datasheet](https://www.pololu.com/docs/pdf/0j12/qtr-8x.pdf) |
| RGB LED                   | 1        | [Datasheet](https://www.farnell.com/datasheets/3497864.pdf) |
| Resistors                 | 220Ω | [Datasheet](https://assets.rs-online.com/v1699613067/Datasheets/7ec977c91977fd4e95a020bd86d6d6c5.pdf) |
| DC Motor Shield Module    | 1        | [Datasheet](https://www.arduino.cc/en/Main/ArduinoMotorShieldR3) |

<a>  
<img src="https://github.com/gabirelul/Linefollower-Robotics-Project/blob/main/images/1.JPEG" width = "500px"></img>  
<img src="https://github.com/gabirelul/Linefollower-Robotics-Project/blob/main/images/2.JPEG" width = "500px"></img>  
</a>

---

## Software Design  
- **Development Environment:** Arduino IDE  
- **Libraries and 3rd-Party Sources:**  
  - LiquidCrystal Library for LCD control  
  - Arduino standard libraries for motor and sensor control  
- **Algorithms and Structures:**  
  - **PID Control:** The robot uses a Proportional-Integral-Derivative (PID) controller to follow the line efficiently.  
  - **ADC Reading:** Sensors are read using the Arduino’s ADC pins, ensuring the robot can detect the black line on a white surface.  
  - **GPIO Control:** Motors and LEDs are controlled through the GPIO pins on the Arduino board.  
- **Serial Debugging:** Serial communication is used to output sensor readings, PID values, and motor adjustments to monitor the robot’s behavior in real time. This helps in troubleshooting and fine-tuning the robot’s performance.  
- **Implemented Code:** The main loop reads sensor data, applies PID control, and adjusts the motor speeds accordingly.

---

## Lab Functionalities in the Project

### Debugging with Serial Communication:
Real-time debugging, allowing me to track sensor values and adjust PID parameters during testing.

### ADC for Sensor Readings:
The Arduino's ADC reads values from the line sensors, enabling the robot to detect the black line on a white surface.

### GPIO Pins for Motor and Sensor Control:
GPIO pins were used to connect and control various components, including motors, sensors.

### Interrupts for Button Presses:
Interrupts handle button presses for starting and stopping the robot, responding immediately without constantly checking the button state.

### PID Control for Line Following:
A PID controller adjusts motor speeds based on sensor input, improving line-following accuracy and stability.

--- 

## Results
  - Successfully built a robot that follows a black line using the QTR-8 sensor array.  
  - Implemented PID control to maintain smooth line following.  
  - Integrated LCD display to show sensor values and robot status.  

## Video Demo

[YouTube](https://youtube.com/shorts/jdu-fO7EqT0)

---

## Conclusions  
- **Learnings:**  
  - Gained experience in sensor calibration, PID control, and real-time motor adjustments.  
  - Learned how to integrate multiple hardware components (sensors, motors, LCD). 

---

## GitHub Repository Structure  
- src/ - Contains all source code  
- hardware/ - Contains hardware schematics and diagrams  
- images/ - Contains images of the project  

---

## Journal  
- **[03.12.2024]:** Started the documentation.  
- **[17.12.2024]:** Hardware section update.  
- **[07.01.2025]:** Hardware section update.  

---

## Bibliography  
https://lastminuteengineers.com/l293d-dc-motor-arduino-tutorial/
-
http://robotresearchlab.com/2019/03/18/how-to-hookup-and-program-a-qtr-8-sensor-array/

---

## License
You can find the project license details in the [License file](https://github.com/gabirelul/Linefollower-Robotics-Project/blob/main/LICENSE).

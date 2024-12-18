# Linefollower Robotics Project

# Table of Contents
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
---

## General Description
<a>
<img src="https://github.com/gabirelul/Linefollower-Robotics-Project/blob/main/images/scheme.jpg" width = "500px"></img>
</a>

This block diagram illustrates the system architecture of the Linefollower

### 1. QTR-8 Sensor Array
- **Connection**: Connected to analog pins 6-11 for line detection.  
- **Function**: The infrared sensors provide HIGH/LOW outputs depending on the surface reflectivity (black or white).  

### 2. DC Motors
- **Control**: Managed via the Motor Shield.  
- **Pins**: The Motor Shield uses digital pins to control motor speed and direction.  
- **Power**: Motors are powered through the Motor Shield’s external 9V input.  

### 3. LCD 16x2 Display
- **Connection**: Connected through an I2C module.  
- **Function**: Displays sensor readings and system data.  

### 4. Potentiometer
- **Connection**: Adjusts the LCD display contrast.  
- **Wiring**: Connected to 5V, GND, and an analog input pin.  


### 5. RGB LED
- **Control**: Red and Green pins are connected to separate digital pins for controlling brightness and color mixing.  
- **Resistors**: 220Ω resistors are added in series with each LED pin to limit current.  


### 6. Power Supply
- **Battery**: The system is powered via a 9V battery connected to the Arduino’s barrel jack input.  
- **Motor Power**: The Motor Shield draws power directly from the 9V battery to drive the motors.  

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
</a>

---

## Software Design
- **Development Environment:**
- **Libraries and 3rd-Party Sources:**
- **Algorithms and Structures:**
- **Implemented Code:**

---

## Results
- **Achievements:**
- **Limitations:**

---

## Conclusions
- **Learnings:**
- **Future Work:**

---

## GitHub Repository Structure
- src/ - Contains all source code
- hardware/ - Contains hardware schematics and diagrams
- images/ - Contains images of the project

---

## Journal
- **[03.12.2024]:** Started the documentation.
- **[17.12.2024]:** Hardware section update.
---

## Bibliography
### Software Resources
### Hardware Resources

---

<h2 href="https://github.com/gabirelul/Linefollower-Robotics-Project/blob/main/LICENSE" target="_blank">License</h2>

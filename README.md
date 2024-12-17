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

1. **QTR-8 Sensor Array**:  
   - Connected to the **Analog pins A0-A5** for reading line data.
   - The output of the IR sensors provides high/low values depending on the reflectivity of the surface.  

2. **DC Motors**:  
   - Controlled via the **Motor Shield**.  
   - Motor Shield pins connect to **digital PWM pins** for speed and direction control.  
   - **Power**: Motors powered through the **Motor Shield's external 9V input**.

3. **LCD 16x2 Display**:  
   - Connected through an **I2C module** to reduce pin usage.  
   - Displays sensor values and data.

4. **Potentiometer**:  
   - Connected to adjust the contrast of the **LCD display**.  
   - Connected to **5V, GND**, and an **analog input pin** for value adjustments.

5. **RGB LED**:  
   - Red and Green connects to separate **PWM pins** for controlling brightness and color mixing.  
   - A 220Ω resistor is added in series with each pin to limit current.

6. **Battery**:  
   - The entire system is powered via a **9V battery**, connected to the Arduino’s barrel jack input.  
   - The **Motor Shield** draws power directly from the 9V battery to drive the motors.  

---

## Hardware Design
<a>
<img src="https://github.com/gabirelul/Linefollower-Robotics-Project/blob/main/images/thinker.jpg" width = "500px"></img>
</a>

### Parts List
| Component                 | Quantity | Datasheet Link                                                                 |
|---------------------------|----------|-------------------------------------------------------------------------------|
| LCD 16x2                  | 1        | [Datasheet](https://components101.com/sites/default/files/component_datasheet/16x2%20LCD%20Datasheet.pdf)             |
| Breadboard                | 1        | [Datasheet](https://components101.com/sites/default/files/component_datasheet/Breadboard%20Datasheet.pdf)                  |
| DC Motors                 | 2        | [Datasheet](https://www.pololu.com/file/download/motor-datasheet.pdf)        |
| Wheels                    | 2        | N/A                    |
| Jumper Cables             | 20+      | [Reference](https://components101.com/wires/jumper-wire)                     |
| 9V Battery                | 1        | N/A      |
| Battery Connector for 9V  | 1        | [Reference](https://www.sparkfun.com/products/67)                            |
| Potentiometer             | 1        | [Datasheet](https://components101.com/sites/default/files/component_datasheet/potentiometer%20datasheet.pdf)               |
| QTR-8 Sensor Array        | 1        | [Datasheet](https://www.pololu.com/file/download/qtr-8a-datasheet.pdf)       |
| RGB LED                   | 1        | [Datasheet](https://components101.com/leds/rgb-led-pinout-datasheet)         |
| Resistors                 | Assorted | [Datasheet](https://components101.com/resistors/resistor-datasheet)          |
| DC Motor Shield Module    | 1        | [Datasheet](https://www.arduino.cc/en/Main/ArduinoMotorShieldR3)             |

<a>
<img src="https://github.com/gabirelul/Linefollower-Robotics-Project/blob/main/images/1.JPEG" width = "500px"></img>
<img src="https://github.com/gabirelul/Linefollower-Robotics-Project/blob/main/images/2.JPEG" width = "500px"></img>
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
[![Demo Video]()]()

---

## Journal
- **[03.12.2024]:** Started the documentation.

---

## Bibliography
### Software Resources
### Hardware Resources

---

<h2 href="https://github.com/gabirelul/Linefollower-Robotics-Project/blob/main/LICENSE" target="_blank">License</h2>

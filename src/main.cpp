#include <LiquidCrystal.h>
#include <Arduino.h>

// LCD Pins
const int RS = 13, EN = 12, D4 = 11, D5 = 10, D6 = 9, D7 = 8;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

// Motor Pins
const int MOTOR2_PIN1 = 7, MOTOR2_PIN2 = 6;
const int MOTOR1_PIN1 = 4, MOTOR1_PIN2 = 5;
const int ENABLE_PIN1 = A5, ENABLE_PIN2 = 3;

// IR Sensor Pins
const int SENSOR_PINS[] = {A0, A1, A2, A3, A4};
const int NR_SENSORS = 5;
int sensorValues[NR_SENSORS];

// Button Pin
const int BUTTON_PIN = 2; // INT0 pin
volatile bool isRunning = false;

// Motor speed
const int MAX_SPEED = 255;
const int BASE_SPEED = 200; // Adjusted for better control

// PID constants
float Kp = 40.0, Ki = 0.0, Kd = 20.0;
float integral = 0, previousError = 0;

// Sensor calibration values
int sensorCalibration[NR_SENSORS][2]; // {min_value, max_value}

// Interrupt Service Routine for INT0
ISR(INT0_vect)
{
  isRunning = !isRunning; // Toggle the running state
}

// Initialize ADC
void initADC()
{
  // Set reference voltage to AVcc
  ADMUX = (1 << REFS0);

  // Enable ADC, set prescaler to 128 for stable readings
  ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

// Read analog value from specified ADC channel
int readADC(uint8_t channel)
{
  // Select ADC channel (0-7)
  ADMUX = (ADMUX & 0xF8) | (channel & 0x07);

  // Start conversion
  ADCSRA |= (1 << ADSC);

  // Wait for conversion to complete
  while (ADCSRA & (1 << ADSC))
    ;

  // Return the ADC value
  return ADC;
}

// Calibrate the sensors
void calibrateSensors()
{
  Serial.println("Calibrating...");

  // Initialize min and max values
  for (int i = 0; i < NR_SENSORS; i++)
  {
    sensorCalibration[i][0] = 1023; // min value (max ADC reading)
    sensorCalibration[i][1] = 0;    // max value (min ADC reading)
  }

  // Read sensor values to calibrate
  for (int i = 0; i < NR_SENSORS; i++)
  {
    int sensorValue = readADC(SENSOR_PINS[i] - A0);
    sensorCalibration[i][0] = min(sensorCalibration[i][0], sensorValue); // Min value
    sensorCalibration[i][1] = max(sensorCalibration[i][1], sensorValue); // Max value
  }

  Serial.println("Calibration complete!");
}

// Set motor speed
void setMotorSpeed(int leftSpeed, int rightSpeed)
{
  // Left Motor
  if (leftSpeed > 0)
  {
    analogWrite(ENABLE_PIN1, leftSpeed);
    digitalWrite(MOTOR1_PIN1, HIGH);
    digitalWrite(MOTOR1_PIN2, LOW);
  }
  else
  {
    analogWrite(ENABLE_PIN1, 0);
    digitalWrite(MOTOR1_PIN1, LOW);
    digitalWrite(MOTOR1_PIN2, LOW);
  }

  // Right Motor
  if (rightSpeed > 0)
  {
    analogWrite(ENABLE_PIN2, rightSpeed);
    digitalWrite(MOTOR2_PIN1, HIGH);
    digitalWrite(MOTOR2_PIN2, LOW);
  }
  else
  {
    analogWrite(ENABLE_PIN2, 0);
    digitalWrite(MOTOR2_PIN1, LOW);
    digitalWrite(MOTOR2_PIN2, LOW);
  }
}

// Read sensor values and apply calibration
int readSensors()
{
  int totalValue = 0;
  int weightedSum = 0;

  for (int i = 0; i < NR_SENSORS; i++)
  {
    int sensorValue = readADC(SENSOR_PINS[i] - A0);

    // Check if the sensor value is within calibrated range
    if (sensorValue < sensorCalibration[i][0] || sensorValue > sensorCalibration[i][1])
    {
      sensorValues[i] = 0; // Line not detected
    }
    else
    {
      sensorValues[i] = sensorValue; // Line detected
    }

    totalValue += sensorValues[i];
    weightedSum += sensorValues[i] * i;
  }

  if (totalValue == 0)
  {
    return -1; // Line not detected
  }

  return weightedSum / totalValue; // Line position
}

void setup()
{
  cli(); // Disable global interrupts during setup

  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.print("Line Follower");
  delay(500);
  lcd.clear();

  // Set motor pins as outputs
  pinMode(MOTOR1_PIN1, OUTPUT);
  pinMode(MOTOR1_PIN2, OUTPUT);
  pinMode(MOTOR2_PIN1, OUTPUT);
  pinMode(MOTOR2_PIN2, OUTPUT);
  pinMode(ENABLE_PIN1, OUTPUT);
  pinMode(ENABLE_PIN2, OUTPUT);

  // Set sensor pins as inputs
  for (int i = 0; i < NR_SENSORS; i++)
  {
    pinMode(SENSOR_PINS[i], INPUT);
  }

  // Configure external interrupt for BUTTON_PIN (INT0)
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Configure as pull-up
  EICRA |= (1 << ISC01);             // Triggers INT0
  EIMSK |= (1 << INT0);              // Enable INT0 interrupt

  // Initialize ADC
  initADC();

  sei(); // Enable global interrupts

  calibrateSensors();

  lcd.print("Setup Complete");
  delay(500);
  lcd.clear();
}

void loop()
{
  int linePosition = readSensors();
  int targetPosition = NR_SENSORS / 2; // Ideal position (center)

  if (isRunning)
  {
    if (linePosition == -1)
    {
      // Line not detected
      lcd.setCursor(0, 0);
      lcd.print("Line: Not Found");
      setMotorSpeed(0, 0);
      return;
    }

    // Calculate error
    float error = targetPosition - linePosition;

    // Calculate PID terms
    integral += error;                        // Sum of errors
    float derivative = error - previousError; // Rate of change of error
    previousError = error;                    // Update for next iteration

    // PID output
    float correction = Kp * error + Ki * integral + Kd * derivative;

    // Adjust motor speeds based on correction
    int leftSpeed = BASE_SPEED + correction;
    int rightSpeed = BASE_SPEED - correction;

    // Limit motor speeds to [0, MAX_SPEED]
    leftSpeed = constrain(leftSpeed, 0, MAX_SPEED);
    rightSpeed = constrain(rightSpeed, 0, MAX_SPEED);

    setMotorSpeed(leftSpeed, rightSpeed);

    // Print PID values to Serial Monitor
    Serial.print("Error: ");
    Serial.print(error);
    Serial.print(" | Integral: ");
    Serial.print(integral);
    Serial.print(" | Derivative: ");
    Serial.print(derivative);
    Serial.print(" | Correction: ");
    Serial.println(correction);

    lcd.setCursor(0, 0);
    if (linePosition < targetPosition - 1)
    {
      lcd.print("Line: Left     ");
    }
    else if (linePosition > targetPosition + 1)
    {
      lcd.print("Line: Right    ");
    }
    else
    {
      lcd.print("Line: Center   ");
    }

    lcd.setCursor(0, 1);
    for (int i = 0; i < NR_SENSORS; i++)
    {
      lcd.print(sensorValues[i] / 100);
      lcd.print(" ");
    }
  }
  else
  {
    setMotorSpeed(0, 0);
    lcd.setCursor(0, 0);
    lcd.print("LF stopped!!  ");
  }

  delay(100);
}

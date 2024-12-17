#include <Arduino.h>
#include <LiquidCrystal.h>
#include <QTRSensors.h>

const int rsPin = 13;
const int enPin = 12;
const int d4Pin = 5;
const int d5Pin = 4;
const int d6Pin = 3;
const int d7Pin = 2;

#define NUM_SENSORS 6
#define EMITTER_PIN QTR_NO_EMITTER_PIN

const uint8_t sensorPins[NUM_SENSORS] = {6, 7, 8, 9, 10, 11};

LiquidCrystal lcd(rsPin, enPin, d4Pin, d5Pin, d6Pin, d7Pin);

QTRSensors qtr;

uint16_t sensorValues[NUM_SENSORS];

void setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Testing...");

  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Calibrating...");
  for (int i = 0; i < 400; i++)
  {
    qtr.calibrate();
    delay(20);
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Calibration Done!");
  delay(1000);
  lcd.clear();
}

void loop()
{
  qtr.read(sensorValues);

  lcd.setCursor(0, 0);
  lcd.print("Sensor Values: ");
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    lcd.print(sensorValues[i] / 100);
    lcd.print(" ");
  }

  long position = 0;
  long totalValue = 0;

  for (uint8_t i = 0; i < NUM_SENSORS; i++)
  {
    position += sensorValues[i] * i;
    totalValue += sensorValues[i];
  }

  if (totalValue != 0)
  {
    position /= totalValue;
  }

  lcd.setCursor(0, 1);
  lcd.print("Line Pos: ");
  lcd.print(position);

  if (position < 2000)
  {
    digitalWrite(A0, HIGH);
    digitalWrite(A1, LOW);
  }
  else if (position > 5000)
  {
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH);
  }
  else
  {
    digitalWrite(A0, LOW);
    digitalWrite(A1, LOW);
  }

  delay(100);
}

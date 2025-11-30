#include <Arduino.h>
#include <Wire.h>

const int LED_PIN  = 7;
const int LED_PIN2 = 6;
const int LED_PIN3 = 5;
const int LED_PIN4 = 4;

const int LIGHT_SENSOR_PIN = A2;
const int lightThreshold = 89;

volatile bool turnOnLED = false;   // Receives '1'
volatile bool turnOffLED = false;  // Receives '0'

// Duration from master (in hours)
volatile int durationHours = 0;

// Converted to seconds
unsigned long remainingSeconds = 0;

unsigned long previousMillis = 0;
const unsigned long interval = 1000;

// ----------------------
// Receive from master
// ----------------------
void receiveEvent(int numBytes) {
  if (numBytes >= 1) {
    durationHours = Wire.read();      // Master sends 1 byte (0–24)
    remainingSeconds = (unsigned long)durationHours * 3600UL;
  }
}

// ----------------------
// Master requests LED state
// ----------------------
void requestEvent() {
  if (digitalRead(LED_PIN) == HIGH)
    Wire.write(1);
  else
    Wire.write(0);
}

void setup() {
  Wire.begin(0x20);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);

  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  pinMode(LED_PIN4, OUTPUT);

  pinMode(LIGHT_SENSOR_PIN, INPUT);
}

void loop() {
  unsigned long now = millis();

  if (now - previousMillis >= interval) {
    previousMillis = now;

    int lightLevel = analogRead(LIGHT_SENSOR_PIN);

  

    // Automatic lighting logic
    if (remainingSeconds > 0) {
      if (lightLevel < lightThreshold) {
        digitalWrite(LED_PIN, HIGH);
        digitalWrite(LED_PIN2, HIGH);
        digitalWrite(LED_PIN3, HIGH);
        digitalWrite(LED_PIN4, HIGH);

        remainingSeconds--;
      } 
      else {
        // Pause timer
        digitalWrite(LED_PIN, LOW);
        digitalWrite(LED_PIN2, LOW);
        digitalWrite(LED_PIN3, LOW);
        digitalWrite(LED_PIN4, LOW);
      }
    }
    else {
      // Time is up
      digitalWrite(LED_PIN, LOW);
      digitalWrite(LED_PIN2, LOW);
      digitalWrite(LED_PIN3, LOW);
      digitalWrite(LED_PIN4, LOW);
    }
  }
}
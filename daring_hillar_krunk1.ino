/*
 * Project: Motion Detection Alarm
 * Author: Junior Embedded Engineer
 * Date: 2024
 * Description: Detects motion using a PIR sensor and triggers a buzzer/LED alarm.
 */

// 1. Define Pin Constants
const int pirPin = 2;      // Input pin for Motion Sensor
const int buzzerPin = 12;  // Output pin for Buzzer
const int ledPin = 13;     // Output pin for LED

// Variable to store the sensor state (0 = No Motion, 1 = Motion Detected)
int motionState = 0;

void setup() {
  // 2. Initialize Pins
  pinMode(pirPin, INPUT);    // Configure PIR pin as input
  pinMode(buzzerPin, OUTPUT);// Configure Buzzer pin as output
  pinMode(ledPin, OUTPUT);   // Configure LED pin as output

  // Initialize Serial Monitor for debugging (optional but good practice)
  Serial.begin(9600);
  Serial.println("System Initialized: Warming up sensor...");
  delay(2000); // Give PIR sensor time to calibrate
}

void loop() {
  // 3. Read Sensor Data
  motionState = digitalRead(pirPin);

  // 4. Logic Control
  if (motionState == HIGH) {
    // Motion Detected!
    digitalWrite(buzzerPin, HIGH); // Turn Buzzer ON
    digitalWrite(ledPin, HIGH);    // Turn LED ON
    Serial.println("ALARM: Motion Detected!");
  } 
  else {
    // No Motion
    digitalWrite(buzzerPin, LOW);  // Turn Buzzer OFF
    digitalWrite(ledPin, LOW);     // Turn LED OFF
  }
  
  delay(100); // Small delay for stability
}
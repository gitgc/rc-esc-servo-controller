#include <Arduino.h>
#include <ESP32Servo.h>
#include <ESC.h>

#define LED_BUILTIN (2) // Built-in LED pin

#define ESC_PIN (33) // ESC control pin

#define ESC_ARM_VALUE (500) // Value to arm the ESC
#define ESC_MIN_SPEED (1040) // speed low just low enough to not move the motor
#define ESC_MAX_SPEED (1240) // maximum speed of the motor

ESC rcESC (ESC_PIN, ESC_MIN_SPEED, ESC_MAX_SPEED, ESC_ARM_VALUE);

void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("Starting RC ESC Controller.");

  // Configure ESC pins
  pinMode(ESC_PIN, OUTPUT);
  // Turn on the built-in LED
  digitalWrite(LED_BUILTIN, HIGH);

  // Initialize the ESC
  rcESC.arm();
  Serial.println("ESC armed.");
}

void loop() {
  Serial.println("Tic");
  delay(1000);
  Serial.println("Tac");
  delay(1000);
  Serial.println("Toe");
  delay(1000);
}

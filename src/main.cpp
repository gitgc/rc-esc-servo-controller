#include <Arduino.h>

#include <ESC.h>
#include <Network.h>

const char* WIFI_SSID = "CHANGE_ME"; // Replace with your WiFi SSID
const char* WIFI_PASSWORD = "CHANGE_ME"; // Replace with your WiFi password
int LISTENING_PORT = 80; // Port for the web server

#define LED_BUILTIN (2) // Built-in LED pin

#define ESC_PIN (33) // ESC control pin
#define ESC_ARM_VALUE (500) // Value to arm the ESC
#define ESC_MIN_SPEED (1040) // speed low just low enough to not move the motor
#define ESC_MAX_SPEED (1240) // maximum speed of the motor

ESC rcESC (ESC_PIN, ESC_MIN_SPEED, ESC_MAX_SPEED, ESC_ARM_VALUE);
Network network(WIFI_SSID, WIFI_PASSWORD);

void setup() {
  Serial.begin(115200);
  delay(1000);

  network.connectToWiFi();

  Serial.println("Starting RC ESC Controller...");
  // Configure ESC pins
  pinMode(ESC_PIN, OUTPUT);
  // Initialize the ESC
  rcESC.arm();
  Serial.println("ESC armed.");

  // Turn on the built-in LED
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  Serial.println("Tic");
  delay(1000);
  Serial.println("Tac");
  delay(1000);
  Serial.println("Toe");
  delay(1000);
}

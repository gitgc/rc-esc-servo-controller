#include <Arduino.h>

#include <ESC.h>
#include <Steering.h>
#include <Network.h>

const char* WIFI_SSID = "CHANGE_ME";
const char* WIFI_PASSWORD = "CHANGE_ME";
int LISTENING_PORT = 80;

#define LED_BUILTIN_PIN (2)
#define ESC_PIN (33)
#define STEERING_PIN (32)

#define ESC_ARM_VALUE (500)
#define ESC_MIN_SPEED (1040)
#define ESC_MAX_SPEED (1240)

#define STEERING_MIN (1000)
#define STEERING_MAX (2000)
#define STEERING_NEUTRAL (1500)

ESC rcESC (ESC_PIN, ESC_MIN_SPEED, ESC_MAX_SPEED, ESC_ARM_VALUE);
Steering steering(STEERING_PIN, STEERING_MIN, STEERING_MAX, STEERING_NEUTRAL);

Network network(WIFI_SSID, WIFI_PASSWORD);

void setup() 
{
    Serial.begin(115200);
    delay(1000);

    network.connectToWiFi();

    Serial.println("Starting RC ESC Controller...");
    pinMode(ESC_PIN, OUTPUT);
    rcESC.arm();
    Serial.println("ESC armed.");

    Serial.println("Starting RC Steering Controller...");
    pinMode(STEERING_PIN, OUTPUT);
    steering.arm();
    Serial.println("Steering armed.");

    pinMode(LED_BUILTIN_PIN, OUTPUT);
    digitalWrite(LED_BUILTIN_PIN, HIGH);
}

void loop() 
{
    Serial.println("Tic");
    delay(1000);
    Serial.println("Tac");
    delay(1000);
    Serial.println("Toe");
    delay(1000);
}

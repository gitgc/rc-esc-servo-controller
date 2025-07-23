#include <Network.h>

Network::Network(const char* ssid, const char* password) {
    this->ssid = ssid;
    this->password = password;
}

Network::~Network() { }

void Network::connectToWiFi() {
    Serial.println("Connecting to WiFi...");
    WiFi.begin(this->ssid, this->password);
    int wifiStatus = WiFi.waitForConnectResult(10000);

    if (wifiStatus != WL_CONNECTED) {
        Serial.println("Failed to connect to WiFi");
        // Using a blocking loop to prevent further execution
        while (true) {
            delay(1000);
        }
    }
    Serial.println("Connected to WiFi!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}

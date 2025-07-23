#include <Network.h>

// Network class constructor
Network::Network(const char* ssid, const char* password, int port) {
    this->ssid = ssid;
    this->password = password;
    this->port = port;
}

// Network class destructor
Network::~Network() {
    // Nothing to destruct
}

void Network::connectToWiFi() {
    Serial.print("Connecting to WiFi");
    WiFi.begin(this->ssid, this->password);

    int maxAttempts = 40;
    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < maxAttempts) {
        delay(500);
        Serial.print(".");
        attempts++;
    }

    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("\nFailed to connect to WiFi :(");    
        // Using a blocking loop to prevent further execution
        while (true) {
            delay(1000);
        }
    }

    Serial.println("\nConnected to WiFi!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}

#ifndef NETWORK_LIBRARY_H
#define NETWORK_LIBRARY_H

#include <Arduino.h>
#include <WiFi.h>

class Network
{
	public:
		Network(const char* ssid, const char* password, int port);
		~Network();
    void connectToWiFi();

	private:
		const char* ssid;
    const char* password;
    int port;
};

#endif // NETWORK_LIBRARY_H

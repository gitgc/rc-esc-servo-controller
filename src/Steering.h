#ifndef Steering_Library
#define Steering_Library

#include <Arduino.h>
#include <ESP32Servo.h>

class Steering
{
	public:
		Steering(byte ESC_pin, int outputMin = 1000, int outputMax = 2000, int outputNeutral = 1500);
		~Steering();
        void arm();
        void setSteering(int steeringValue); // set the steering servo position

	private:
    	Servo mySteeringServo; // create servo object to control a steering servo
		byte oPin; // steering servo output Pin
        int oMin = 1000; // minimum pulse width for steering servo
        int oMax = 2000; // maximum pulse width for steering servo
        int oNeutral = 1500; // neutral position for steering servo
        
};

#endif

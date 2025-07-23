
#include <Steering.h>

Steering::Steering(byte ESC_pin, int outputMin, int outputMax, int outputNeutral) 
{
    oPin = ESC_pin;
    oMin = outputMin;
    oMax = outputMax;
    oNeutral = outputNeutral;
}

Steering::~Steering() 
{ 
}

void Steering::arm()
{
	mySteeringServo.attach(oPin);
    setSteering(oNeutral);
}

void Steering::setSteering(int steeringValue) 
{
    // Ensure the steering value is within the defined limits
    if (steeringValue < oMin) {
        steeringValue = oMin;
    } else if (steeringValue > oMax) {
        steeringValue = oMax;
    }
    
    mySteeringServo.writeMicroseconds(steeringValue);
}

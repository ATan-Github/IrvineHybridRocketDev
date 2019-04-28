#include <Preflight.h>

//Assigns preflight to the pins on Arduino
Preflight preflight = {6,7,8,9,10};

//Begins the setup(startup) procedure for the linear actuator
void setup()
{
Serial.begin(9600);
preflight.startup();
}

//Loops the precheck fxn with a 5 sec delay
void loop()
{
preflight.precheck();
delay(5000);
}

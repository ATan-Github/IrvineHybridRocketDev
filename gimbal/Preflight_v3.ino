#include <Preflight.h>
#include <Constants.h>

//Assigns preflight to the pins on Arduino
Preflight preflight = {r1,r2,r3,r4,vcc};

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

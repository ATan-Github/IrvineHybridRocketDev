#include <Preflight.h>

Preflight preflight = {6,7,8,9,10};

void setup()
{
Serial.begin(9600);
preflight.startup();
}

void loop()
{
preflight.precheck();
delay(5000);
}

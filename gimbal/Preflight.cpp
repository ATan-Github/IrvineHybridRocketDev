//Preflight library .cpp
#include <Arduino.h>
#include <LA_1.h>
#include <LA_2.h>
#include <Preflight.h>



Preflight::Preflight(int r1, int r2, int r3, int r4, int vcc)
{
    LA_1 la1 = {r1, r2};
    LA_2 la2 = {r3, r4};
    pinMode(vcc, OUTPUT);
    _r1 = r1;
    _r2 = r2;
    _r3 = r3;
    _r4 = r4;
    _vcc = vcc;
}

void Preflight::stopactuators()
{
    digitalWrite(_vcc, LOW);
}

void Preflight::startactuators()
{
    digitalWrite(_vcc, HIGH);
}



void Preflight::startup()
{
    startactuators();
    
    la1.retract(2000);
    la2.retract(2000);
    delay(1000);
    la1.extend(1000);
    la2.extend(1000);
    
    stopactuators();
}

void Preflight::precheck()
{
    startactuators();

    la1.retract(1000);
    delay(500);
    la1.extend(1000);
    delay(500);

    la1.move(1000);
    delay(500);
    la1.move(-1000);
    delay(500);

    la2.move(1000);
    delay(500);
    la2.move(-1000);
    delay(500);

    la2.move(-1000);
    delay(500);
    la2.move(1000);
    delay(500);

    stopactuators();
}

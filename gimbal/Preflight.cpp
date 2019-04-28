//Preflight library .cpp
#include <Arduino.h>
#include <LA_1.h>
#include <LA_2.h>
#include <Preflight.h>

int relay1, relay2, relay3, relay4;

Preflight::Preflight(int r1, int r2, int r3, int r4, int vcc)
{
    pinMode(vcc, OUTPUT);
    _r1 = r1;
    _r2 = r2;
    _r3 = r3;
    _r4 = r4;
    _vcc = vcc;
    relay1 = _r1;
    relay2 = _r2;
    relay3 = _r3;
    relay4 = _r4;
}

void Preflight::stopactuators()
{
    digitalWrite(_vcc, LOW);
}

void Preflight::startactuators()
{
    digitalWrite(_vcc, HIGH);
}


struct Preflight::LA_1 la1 = {relay1, relay2};
struct Preflight::LA_2 la2 = {relay3, relay4};

void Preflight::startup()
{
    startactuators();
    la1.retract;
    la2.retract;
    delay(2000);
    la1.extend;
    la2.extend;
    delay(1000);
    stopactuators();
}

void Preflight::precheck()
{
    startactuators();

    la1.retract;
    delay(1000);
    la1.extend;
    delay(1000);

    la1.extend;
    delay(1000);
    la1.retract;
    delay(1000);

    la2.retract;
    delay(1000);
    la2.extend;
    delay(1000);

    la2.extend;
    delay(1000);
    la2.retract;
    delay(1000);

    stopactuators();
}

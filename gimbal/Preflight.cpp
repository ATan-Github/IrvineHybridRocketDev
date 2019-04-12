//Preflight library .cpp
#include <Arduino.h>
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

struct Preflight::Extend
{
    Extend(const int& relay1, const int& relay2):
        r1(relay1), r2(relay2)
    {
        pinMode(r1, OUTPUT);
        pinMode(r2, OUTPUT);
        digitalWrite(r1, LOW);
        digitalWrite(r2, HIGH);
    }

    int r1, r2;
};

struct Preflight::Retract
{
    Retract(const int& relay1, const int&relay2):
        r1(relay1), r2(relay2)
    {
        pinMode(r1, OUTPUT);
        pinMode(r2, OUTPUT);
        digitalWrite(r1, HIGH);
        digitalWrite(r2, LOW);
    }

    int r1, r2;
};

struct Preflight::LA_1
{
    LA_1(const int& relay1, const int& relay2):
    r1(relay1), r2(relay2){}

    int r1, r2;
    float position = -1;
    struct Extend extend = {r1,r2};
    struct Retract retract = {r1,r2};
};

struct Preflight::LA_2
{
    LA_2(const int& relay3, const int& relay4):
    r3(relay3), r4(relay4){}

    int r3, r4;
    float position = -1;
    struct Extend extend = {r3,r4};
    struct Retract retract = {r3, r4};
};

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

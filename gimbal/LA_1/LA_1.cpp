
#include <Arduino.h>
#include <LA_1.h>

LA_1::LA_1(int r1, int r2)
{
    pinMode(r1, OUTPUT);
    pinMode(r2, OUTPUT);

    _r1 = r1;
    _r2 = r2;
}

void LA_1::extend(int t)
{
    digitalWrite(_r1, LOW);
    digitalWrite(_r2, HIGH);
    delay(t);
}

void LA_1::retract(int t)
{
    digitalWrite(_r1, HIGH);
    digitalWrite(_r2, LOW);
    delay(t);
}

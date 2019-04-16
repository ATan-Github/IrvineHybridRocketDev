
#include <Arduino.h>
#include <LA_2.h>

LA_2::LA_2(int r3, int r4)
{
    pinMode(r3, OUTPUT);
    pinMode(r4, OUTPUT);

    _r3 = r3;
    _r4 = r4;
}

void LA_2::extend(int t2)
{
    digitalWrite(_r3, LOW);
    digitalWrite(_r4, HIGH);
    delay(t2);
}

void LA_2::retract(int t2)
{
    digitalWrite(_r3, HIGH);
    digitalWrite(_r4, LOW);
    delay(t2);
}

void LA_2::move(int t2)
{
    if(t2 >= 0)
    {
        digitalWrite(_r3, LOW);
        digitalWrite(_r4, HIGH);
        delay(t2);
    }
    else
    {
        digitalWrite(_r3, HIGH);
        digitalWrite(_r4, LOW);
        delay(-t2);
    }
}

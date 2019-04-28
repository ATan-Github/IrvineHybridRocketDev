//***************************************************
// File: LA_1.cpp
// Desc: Contains the functions for 1 linear actuator
//***************************************************

#include <Arduino.h>
#include <LA_1.h>

LA_1::LA_1(int r1, int r2)
{
    pinMode(r1, OUTPUT);
    pinMode(r2, OUTPUT);

    _r1 = r1;
    _r2 = r2;
}//end LA_1 constructor

void LA_1::extend(int t)
{
    digitalWrite(_r1, LOW);
    digitalWrite(_r2, HIGH);
    delay(t);
}//end extend

void LA_1::retract(int t)
{
    digitalWrite(_r1, HIGH);
    digitalWrite(_r2, LOW);
    delay(t);
}//end retract

//Moves the linear actuator a distance of 25mm/s(time), t is either negative or positive
void LA_1::move(int t)
{
    //Extends if t is positive
    if(t > 0)
    {
        digitalWrite(_r1, LOW);
        digitalWrite(_r2, HIGH);
        delay(t);
    }
    //Retracts if t is negative
    else if( t < 0)
    {
        digitalWrite(_r1, HIGH);
        digitalWrite(_r2, LOW);
        delay(-t);
    }
    else
    {
        exit(0);
    }
}//end move

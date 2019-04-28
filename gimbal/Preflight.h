
#ifndef Preflight_h
#define Preflight_h
#include <Arduino.h>

class Preflight
{
    public:
        Preflight(int r1, int r2, int r3, int r4, int vcc);
        void startactuators(); // temporary
        void stopactuators(); // temporary
        void startup(); // zeros the actuator positions
        void precheck(); // goes through 4 simple directions
    private:
        int _r1;
        int _r2;
        int _r3;
        int _r4;
        int _vcc;
};

#endif

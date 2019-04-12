
#ifndef Preflight_h
#define Preflight_h
#include <Arduino.h>

class Preflight
{
    public:
        Preflight(int r1, int r2, int r3, int r4, int vcc);
        struct Extend;
        struct Retract;
        struct LA_1;
        struct LA_2;
        void startactuators();
        void stopactuators();
        void startup();
        void precheck();
    private:
        int _r1;
        int _r2;
        int _r3;
        int _r4;
        int _vcc;
};

#endif

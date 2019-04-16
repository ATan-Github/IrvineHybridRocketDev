
#ifndef LA_2_h
#define LA_2_h
#include <Arduino.h>

class LA_2
{
    public:
        LA_2(int r3, int r4);
        void extend(int t2);
        void retract(int t2);
    private:
        int _r3;
        int _r4;
};

#endif

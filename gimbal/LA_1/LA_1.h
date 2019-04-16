
#ifndef LA_1_h
#define LA_1_h
#include <Arduino.h>

class LA_1
{
    public:
        LA_1(int r1, int r2);
        void extend(int t);
        void retract(int t);
    private:
        int _r1;
        int _r2;
};

#endif

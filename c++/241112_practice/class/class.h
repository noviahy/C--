#ifndef CLASS_H
#define CLASS_H 

#include <iostream>

class Carculator
{
private:
    int plusN = 0;
    int subN = 0;
    int multN = 0;
    int divN = 0;

public:
    Carculator(int num = 0)
    {
        plusN = num;
        subN = num;
        multN = num;
        divN = num;
    }
    float Plus(float a, float b);
    float Sub(float a, float b);
    float Mult(float a, float b);
    float Div(float a, float b);
    void ShowOpCount();
};

#endif
#include "class.h"

float Carculator::Plus(float a, float b)
{
    plusN++;
    return a + b;
}

float Carculator::Sub(float a, float b)
{
    subN++;
    return a - b;
}

float Carculator::Mult(float a, float b)
{
    multN++;
    return a * b;
}

float Carculator::Div(float a, float b)
{
    divN++;
    return a / b;
}

void Carculator::ShowOpCount()
{
    std::cout<< "plus: " << plusN << "subtract: " << subN << "multiple: " << multN << "divide: " << divN << std::endl;
}

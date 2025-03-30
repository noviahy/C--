#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include "Point.h"
#include <iostream>

class Rectangle{
    private:
    Point upLeft;
    Point lowRight;

    public:
    Rectangle(int x1, int y1, int x2, int y2);
    void ShowRecInfo() const;
};
#endif
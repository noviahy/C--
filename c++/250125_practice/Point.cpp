#include <iostream>
#include "Point.h"

Point::Point(const int &xpos, const int &ypos)
{
    if (!SetX(xpos) || !SetY(ypos)) // 0~100 범위 검증
    {
        std::cout << "초기화 값 오류!" << std::endl;
        x = 0; // 기본값 설정
        y = 0;
    }
}

int Point::GetX() const { return x; }
int Point::GetY() const { return y;}

bool Point::SetX(int xpos)
{
    if (0 > xpos || xpos > 100)
    {
        std::cout << "벗어난 범위" << std::endl;
        return false;
    }
    x = xpos;
    return true;
}

bool Point::SetY(int ypos)
{
    if (0 > ypos || ypos > 100)
    {
        std::cout << "벗어난 범위" << std::endl;
        return false;
    }
    y = ypos;
    return true;
}
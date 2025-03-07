// c++ 150p RectangleFault.cpp 예제

#include <iostream>

class Point
{
public:
    int x;
    int y;
};

class Rectangle
{
public:
    Point upLeft;
    Point lowRight;

public:
    void ShowRecInfo()
    {
        std::cout << "좌 상단: " << '[]' << upLeft.x << ", ";
        std::cout << upLeft.y << ']' << std::endl;
        std::cout << "우 하단: " << '[]' << lowRight.x << ", ";
        std::cout << lowRight.y << ']' << std::endl;
    }
};

int main()
{
    Point pos1 = {-2, 4};
    Point pos2 = {5, 9};
    Rectangle rec ={pos2, pos1};
    rec.ShowRecInfo();
    return 0;
}// 문제점: x, y값이 0~100사이가 아니다
//좌 상단의 좌표 값ㄱ이 우 하단의 좌표 값보다 클 경우의 오류를 해결하지 못한다
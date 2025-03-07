#include <iostream>
using namespace std;

// 166p 문제 4-2[다양한 클래스의 정의]문제-캡슐화

class Point
{
private:
    int xpos, ypos;

public:
    void Init(int x, int y)
    {
        xpos = x;
        ypos = y;
    }
    void ShowPointInfo() const
    {
        cout << "[" << xpos << "," << ypos << "]" << endl;
    }
};

// 좌표상의 위치 정보, 반지름 길이 정보를 저장 및 출력
class Circle
{
private:
    int radius;
    Point point;

public:
    void Take(int x, int y, int r)
    {
        point.Init(x, y);
        radius = r;
    }

    void ShowCircle() const
    {
        cout << "radius: " << radius << endl;
        point.ShowPointInfo();
    }
};

// 2개의 Circle 만들기
class Ring
{ // Circle를 기반
private:
    Circle circle1;
    Circle circle2;

public:
    void Init(int cir1x, int cir1y, int radius1, int cir2x, int cir2y, int radius2)
    {
        circle1.Take(cir1x, cir2y, radius1);
        circle2.Take(cir2x, cir2y, radius2);
    }
    void ShowRingInfo() const
    {
        cout << "Inner Circle Info..."
             << endl;
        circle1.ShowCircle();
        cout << "Outter Circle Info..."
             << endl;
        circle2.ShowCircle();
    }
};

int main()
{
    Ring ring;
    ring.Init(1, 1, 4, 2, 2, 9);
    ring.ShowRingInfo();
    return 0;
}
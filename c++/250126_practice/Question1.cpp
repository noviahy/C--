// 166p 문제 4-2[다양한 클래스의 정의]문제-캡슐화
//190p의 문제 4-3 생성자를 모두 설정해주기

#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;

public:
    Point(int x, int y) 
    : xpos(x), ypos(y){}

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
    Circle(int x, int y, int r)
    : point(x,y), radius(r){}

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
    Ring(int cir1x, int cir1y, int radius1, int cir2x, int cir2y, int radius2)
    : circle1(cir1x, cir2y, radius1), circle2(cir2x, cir2y, radius2){ }

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
    Ring ring(1, 1, 4, 2, 2, 9);
    ring.ShowRingInfo();
    return 0;
}
// 468p
// C++ 기반의 데이터 입출력
// 2차원 배열 접근에 대한 연산자 오버로딩...

#include <iostream>
#include <cstring>
using namespace std;

class Pointx
{
public:
    friend ostream &operator<<(ostream &os, const Pointx &pos);
};

class Pointy : Pointx
{
private:
    int num;

public:
    Pointy(int number)
    :num(number) {};

    friend ostream &operator<<(ostream &os, const Point &pos);
};

class BoundCheck2DIntArray
{
private:
    Pointx x;
    Pointy y;

public:
    BoundCheck2DIntArray(int x, int y = 0)
        : xpos(x), ypos(y)
    {
        arr = new Point[xpos][ypos];
    }

    Point operator[](int idx) const
    {
        if (idx < 0 || idx > xpos)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
    }

    Point operator[]()
    {
    }
};

int main()
{
    BoundCheck2DIntArray arr2d(3, 4);

    for (int n = 0; n < 3; n++)
        for (int m = 0; m < 4; m++)
            arr2d[n][m] = n + m;

    return 0;
}
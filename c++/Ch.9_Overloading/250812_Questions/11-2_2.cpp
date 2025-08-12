// 468p
// C++ 기반의 데이터 입출력
// 2차원 배열 접근에 대한 연산자 오버로딩...

#include <iostream>
#include <cstring>
using namespace std;

class Pointx
{
private:
    int ypos;
    Pointy *arry;

public:
    Pointx(int y)
        : ypos(y) { arry = new Pointy[ypos]; }
    
    Pointy &operator[](int idx) const
    {
        if (idx < 0 || idx > ypos)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return arry[idx];
    }
    
    friend ostream &operator<<(ostream &os, const Pointx &pos);
};

class Pointy
{
public:
    friend ostream &operator<<(ostream &os, const Pointx &pos);
};

class BoundCheck2DIntArray
{
private:
    int xpos;
    int ypos;
    Pointx *arrx;

public:
    BoundCheck2DIntArray(int x, int y = 0)
        : xpos(x), ypos(y)
    {
        arrx = new Pointx[xpos];
        Pointx(ypos);
    }

    Pointx &operator[](int idx)
    {
        if (idx < 0 || idx > xpos)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return arrx[idx];
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
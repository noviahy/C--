// p418
// 다항 연산자 오버로딩

#include <iostream>
#include <cmath>
using namespace std;

class Point
{
private:
    int xpos;
    int ypos;

public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}

    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }

    Point operator+() const
    {
        if (xpos > 0 && ypos < 0)
            return Point(xpos, -ypos);
        else if (xpos < 0 && ypos > 0)
            return Point(-xpos, ypos);
        else if (xpos < 0 && ypos < 0)
            return Point(-xpos, -ypos);
        else
            return Point(xpos, ypos);
    }

    friend Point operator-(const Point &ref);

    Point &operator~()
    {
        int i = 0;
        int arr[32];
        int num = xpos;
        ypos = 0;

        while (num > 0)
        {
            arr[i++] = num % 2;
            num /= 2;
        }

        for (int j = 0; j < i; j++)
            arr[j] = (arr[j] == 0) ? 1 : 0;

        for (int j = 0; j < i; j++)
            ypos += arr[j] * pow(2, j);

        return *this;
    }
};

Point operator-(const Point &ref)
{
    if (ref.xpos > 0 && ref.ypos < 0)
        return Point(-ref.xpos, ref.ypos);

    else if (ref.xpos < 0 && ref.ypos > 0)
        return Point(ref.xpos, -ref.ypos);

    else if (ref.xpos > 0 && ref.ypos > 0)
        return Point(-ref.xpos, -ref.ypos);

    else
        return Point(ref.xpos, ref.ypos);
}

int main()
{
    Point pos1(1, 2);
    Point pos2 = -pos1;

    Point pos3(-1, -2);
    Point pos4 = +pos3;

    Point pos5(10, 0);
    pos5 = ~pos5;
    

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();
    pos4.ShowPosition();
    pos5.ShowPosition();

    return 0;
}
#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;

public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }

    int Getx() const { return xpos; }
    int Gety() const { return ypos; }
    int Setx(int x) { xpos = x; }
    int Sety(int y) { ypos = y; }
};

template <typename T1>
void SwapData(T1 &obj)
{
    int temp;
    temp = obj.Getx();
    obj.Setx(obj.Gety());
    obj.Sety(temp);
}

template <class T2>
T2 SumArray(T2 arr[], int len)
{
    T2 sum = 0;
    for (int i = 0; i < len; i++)
        sum += arr[i];
    return sum;
}

int main()
{
    Point point(3, 4);
    point.ShowPosition();

    SwapData(point);
    point.ShowPosition();

    int arr1[3] = {1, 2, 3};
    double arr2[3] = {1.1, 2.2, 3.3};

    cout << SumArray(arr1, 3) << endl;
    cout << SumArray(arr2, 3) << endl;

    return 0;
}
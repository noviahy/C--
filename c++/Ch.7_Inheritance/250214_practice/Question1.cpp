// 312에 있는 문제 1번
#include <iostream>
using namespace std;

// Square와 Rectangle 클래스의 상속관계 구성하기
//..? 뭘 상속해야하지... 넓이 구하는 공식?

class Rectangle
{ // 클래스 채우기
private:
    int x;
    int y;

public:
    Rectangle(int num1, int num2)
        : x(num1), y(num2) {}

    int calculate() const
    {
        
        return x * y;
    }
    void ShowAreaInfo() const
    {
        cout << "area: " << calculate() << endl;
    }
};

class Square : public Rectangle
{ // 이것도
public:
    Square(int num3)
        : Rectangle(num3, num3) {}
};

int main()
{
    Rectangle rec(4, 3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}//완

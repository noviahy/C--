// 452p
// 깊은 복사를 하는 대입 연산자의 정의

#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
    int num1, num2;

public:
    Gun(int n1 = 0, int n2 = 0) : num1(n1), num2(n2) {}
    void ShowData() { cout << num1 << ", " << num2 << endl; }

    Gun &operator=(const Gun &ref)
    {
        cout << "Gun& operator = ()" << endl;
        num1 = ref.num1;
        num2 = ref.num2;
        return *this;
    }
};

class Police : public Gun
{
private:
    int num3, num4;

public:
    Police(int n1, int n2, int n3, int n4)
        : Gun(n1, n2), num3(n3), num4(n4) {}
    void ShowData()
    {
        Gun::ShowData();
        cout << num3 << ", " << num4 << endl;
    }

    Police& operator=(const Police& ref){
        cout<<"Police& operator=()"<<endl;
        Gun::operator=(ref);
        num3 = ref.num3;
        num4 = ref.num4;
        return *this;
    }
};

int main()
{
    Second ssrc(111, 222, 333, 444);
    Second scpy(0, 0, 0, 0);
    scpy = ssrc;
    scpy.ShowData();

    return 0;
}
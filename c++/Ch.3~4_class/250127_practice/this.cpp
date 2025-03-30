// p198에 있는 this 예제
// 이 코드를 수정하며 this가 의미하는 것을 찾아보기\

#include <iostream>
using namespace std;

class TwoNumber
{
private:
    int num1;
    int num2;

public:
    /*  TwoNumber(int num1, int num2)
        {
            this->num1 = num1;
            this->num2 = num2;
        }*/
    // 1번

    TwoNumber(int num1, int num2)
        : num1(num1), num2(num2) {} // 2번

    void ShowTwoNumber()
    {
        cout << this->num1 << endl;
        cout << this->num2 << endl;
    }
};

int main()
{
    TwoNumber two(2, 4);
    two.ShowTwoNumber();
    return 0;
}
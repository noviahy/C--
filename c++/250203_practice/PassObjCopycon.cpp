// 230p에 있는 복사 생성자 호출 시점 확인

#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num;

public:
    SoSimple(int n) : num(n) {}
    SoSimple(const SoSimple &copy) : num(copy.num)
    {
        cout << "Called SoSimple(const SoSimple& copy)" << endl;
    }
    void ShowData()
    {
        cout << "num: " << endl;
    }
};

void SimpleFuncObj(SoSimple ob)
{
    ob.ShowData();
}

int main()
{
    SoSimple obj(7);
    cout << "함수호출 전" << endl;
    SimpleFuncObj(obj);
    cout << '함수호출 후' << endl;
    return 0;
}
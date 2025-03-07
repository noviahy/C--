// 200p에 있는 예제
// &인데 왜 반환형은 주소가 아닌가가 궁금함
#include <iostream>
using namespace std;

class SelfRef
{
private:
    int num;

public:
    SelfRef(int n) : num(n)
    {
        cout << "객체생성" << endl;
    }

    SelfRef &Adder(int n)
    {
        num += n;
        return *this;
    }
    SelfRef &ShowTwoNumber()
    {
        cout << num << endl;
        return *this;
    }
};

int main()
{
    SelfRef obj(3);
    SelfRef &ref = obj.Adder(2);

    obj.ShowTwoNumber();
    ref.ShowTwoNumber();

    ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();//이게 뭐여
    return 0;
}
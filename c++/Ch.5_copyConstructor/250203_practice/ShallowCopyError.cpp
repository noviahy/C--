// 221p에 있는 디폴트 복사 생성자의 문제점 찾기
#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char *name;
    int age;

public:
    Person(char *myname, int myage)
    {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }
    void ShowPersonInfo() const
    {
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
    }
    ~Person()
    {
        delete[] name;
        cout << "called destructor!" << endl;
    }
};

int main()
{
    Person man1("Lee dong woo", 29);
    Person man2 = man1;
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}//분명 안 되는 예시라고 써있는데 왜 called destructor!가 두번 정상으로 나오지?
// delet가 같은 name에 2번 호출되어 오류가 발생할 수도 있지만 운 좋게 안 발생했어요
// man2의 ~Person이 먼저 호출된다. 역순이기 때문.
//<<<얕은 복사>>>
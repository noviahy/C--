// 221p에 있는 디폴트 복사 생성자의 문제점 고치기
// 깊은 복사
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

    explicit Person(const Person &copy)
        : age(copy.age)
    {
        int len = strlen(copy.name) + 1;
        name = new char[len];
        strcpy(name, copy.name);
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
    Person man2(man1);
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}
#include <iostream>
#include <cstring>
using namespace std;

// 적절한 생성자와 소멸자 정의와 확인을 위한 main함수의 정의
class MyFriendInfo
{
private:
    char *name;
    int age;

public:
    MyFriendInfo(char *n, int old)
        : age(old)
    {
        name = new char[strlen(n) + 1];// 동적 메모리 할당이 꼭 필요하다!!!, 아직 메모리가 없기 때문이다!
        strcpy(name, n);
    }

    void ShowMyFriendInfo()
    {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
    }

    ~MyFriendInfo()
    {
        delete name; // 할당된 주소를 꼭 delete 해주어야한다!! 계속 기억기 ㅇㅇ
        cout << "~MyFriendInfo" << endl;
    }
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
    char *addr;
    char *phone;

public:
    MyFriendDetailInfo(char *n, int old, char *loc, char *num)
        : MyFriendInfo(n, old)
    {
        addr = new char[strlen(loc) + 1];  // 동적 할당
        phone = new char[strlen(num) + 1]; // 동적 할당

        strcpy(addr, loc);
        strcpy(phone, num);
    }

    void ShowMyFriendDetailInfo()
    {
        ShowMyFriendInfo();
        cout << "address: " << addr << endl;
        cout << "phone number: " << phone << endl
             << endl;
    }

    ~MyFriendDetailInfo()
    {
        delete addr;
        delete phone;
        cout << "~MyFriendDetailInfo" << endl;
    }
};

int main()
{
    char name[10] = "Lisa";
    int age = 22;
    char address[10] = "seongnam";
    char phone[20] = "010-1111-2222";

    MyFriendDetailInfo info(name, age, address, phone);
    info.ShowMyFriendDetailInfo();
    return 0;
}
// 190p?�� 문제 4-3

#include <iostream>
#include <cstring>
using namespace std;

class NameCard
{
private:
    char *name;
    char *company;
    char *phone;
    int rank;

public:
    NameCard(char *n, char *c, char *p, int r)
        : name(nullptr), company(nullptr), phone(nullptr), rank(r)
    {
        name = AllocateAndCopy(n);

        company = AllocateAndCopy(c);

        phone = AllocateAndCopy(p);
    }

    const char *GetRank() const
    {
        switch (rank)
        {
        case CLERK:
            return "���";
        case SENIOR:
            return "����";
        case ASSIST:
            return "�븮";
        case MANAGER:
            return "����";
        default:
            return "�� �� ����";
        }
    }

    void ShowNameCardInfo() const
    {
        cout << "�̸�: " << name << endl;
        cout << "ȸ��: " << company << endl;
        cout << "��ȭ��ȣ: " << phone << endl;
        cout << "����: " << GetRank() << endl << endl;
    }

    ~NameCard()
    {
        delete[] name;
        delete[] company;
        delete[] phone;
    }

private:
    char *AllocateAndCopy(const char *str)
    {
        char *newstr = new char[strlen(str) + 1];
        strcpy(newstr, str);
        return newstr;
    }
};

enum COMP_POS
{
    CLERK,
    SENIOR,
    ASSIST,
    MANAGER
};

int main()
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard manAssist("Kim", "ABCEng", "010-5555-6666", COMP_POS::ASSIST);

    manClerk.ShowNameCardInfo();
    manSenior.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
    return 0;
}
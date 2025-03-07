// p 226p Question

#include <iostream>
#include <cstring>
using namespace std;

enum COMP_POS
{
    CLERK,
    SENIOR,
    ASSIST,
    MANAGER
};

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

    explicit NameCard(const NameCard &copy)
    : name(nullptr), company(nullptr), phone(nullptr), rank(copy.rank)
    {
        name = AllocateAndCopy(copy.name);

        company = AllocateAndCopy(copy.company);

        phone = AllocateAndCopy(copy.phone);
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
        cout << "����: " << GetRank() << endl
             << endl;
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



int main()
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard copy1(manClerk);
    NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard copy2(manSenior);
    NameCard manAssist("Kim", "ABCEng", "010-5555-6666", COMP_POS::ASSIST);
    NameCard copy3(manAssist);

    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();
    copy3.ShowNameCardInfo();

    return 0;
}
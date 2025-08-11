// 452p
// 깊은 복사를 하는 대입 연산자의 정의

#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
    int bullet;

public:
    Gun(int bnum) : bullet(bnum) {}
    void Shot()
    {
        cout << "BBANG!" << endl;
        bullet--;
    }

    Gun(const Gun& bum){
        bullet = bum.bullet;
    }
};

class Police
{
private:
    int handcuffs;
    Gun *pistol;

public:
    Police(int bnum, int bcuff)
        : handcuffs(bcuff)
    {
        if (bnum > 0)
            pistol = new Gun(bnum);
        else
            pistol = NULL;
    }

    void PutHandcuff()
    {
        cout << "SNAP!" << endl;
        handcuffs--;
    }

    void Shot()
    {
        if (pistol == NULL)
            cout << "Hut BBANG!" << endl;
        else
            pistol->Shot();
    }

    Police &operator=(const Police pol)
    {
        handcuffs = pol.handcuffs;
        pistol = new Gun(*pol.pistol);

        return *this;
    }

    ~Police()
    {
        if (pistol != NULL)
            delete pistol;
    }
};

int main()
{
    Police pman1(5, 3);
    pman1.Shot();
    pman1.PutHandcuff();

    Police pman2 = pman1;
    pman2.Shot();
    pman2.PutHandcuff();

    return 0;
}
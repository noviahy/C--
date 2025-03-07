#include <iostream>
using namespace std;

class FruitSeller
{
private:
    const int APPLE_PRICE; // ����� ���� ���� (���� �Ұ�)
    int numOfApple;        // �Ǹ��ڰ� ������ ��� ����
    int myMoney;           // �Ǹ��ڰ� ������� ��

public:
    FruitSeller(int price, int num, int money)
        : APPLE_PRICE(price), numOfApple(num), myMoney(money)
    {
    }

    int GetApplePrice() const
    {
        return APPLE_PRICE;
    }

    int SaleApples(int money)
    {
        int num = money / APPLE_PRICE; // �����ڰ� �� �� �ִ� ��� ���� ���
        if (num > numOfApple)
        { // �����ִ� ������� ���� ��û�� ���
            num = numOfApple;
        }
        numOfApple -= num;             // �Ǹ� �� ���� ��� ���� ����
        myMoney += num * APPLE_PRICE;  // �Ǹŵ� �ݾ׸� �������� �߰�
        return num;                    // ������ �Ǹŵ� ��� ���� ��ȯ
    }

    void ShowSalesResult() const
    {
        cout << "���� ���: " << numOfApple << endl;
        cout << "�Ǹ� ����: " << myMoney << endl
             << endl;
    }
};

class FruitBuyer
{
private:
    int myMoney;      // �����ڰ� ������ ��
    int numOfApples;  // �����ڰ� ������ ��� ����

public:
    void InitMembers(int money)
    {
        myMoney = money;
        numOfApples = 0;
    }

    void BuyApples(FruitSeller &seller, int money)
    {
        if (money < seller.GetApplePrice())
        { // �ּ� 1�� ���ݺ��� ������ ����
            cout << "�ݾ��� �����մϴ�. �ּ� " << seller.GetApplePrice() << "�� �̻� �Է��� �ּ���." << endl;
            return;
        }
        if (money > myMoney)
        { // ���� �ݾ��� ������ ������ Ŭ ��� ����
            cout << "�ܾ��� �����մϴ�." << endl;
            return;
        }

        int numToBuy = money / seller.GetApplePrice(); // ���� ������ ��� ���� ���
        if (numToBuy < 1)
        { // 1�� �̻��� ����� �������� ���� ���
            cout << "1�� �̻��� ����� �����ؾ� �մϴ�." << endl;
            return;
        }

        int purchasedApples = seller.SaleApples(money);
        if (purchasedApples == 0)
        { // �Ǹ����� ����� ������ ���
            cout << "�Ǹ����� ����� �����մϴ�." << endl;
            return;
        }

        numOfApples += purchasedApples;                      // ������ ��� ���� �߰�
        myMoney -= purchasedApples * seller.GetApplePrice(); // ���� ���� �ݾ� ����
    }

    void ShowBuyResult() const
    {
        cout << "���� �ܾ�: " << myMoney << endl;
        cout << "��� ����: " << numOfApples << endl
             << endl;
    }
};

int main()
{
    FruitSeller seller(1000, 20, 0); // ��� ���� 1000��, �ʱ� ��� 20��, �ʱ� ���� 0��
    FruitBuyer buyer;
    buyer.InitMembers(5000);         // ������ �ʱ� �ڱ� 5000��

    // ���� �õ�
    buyer.BuyApples(seller, 100);    // 100������ ���� �õ� (����)
    buyer.BuyApples(seller, 1000);   // 1000������ ���� �õ� (����, 1�� ����)
    buyer.BuyApples(seller, 2500);   // 2500������ ���� �õ� (����, 2�� ����)

    // ��� ���
    cout << "���� �Ǹ����� ��Ȳ" << endl;
    seller.ShowSalesResult();

    cout << "���� �������� ��Ȳ" << endl;
    buyer.ShowBuyResult();

    return 0;
}

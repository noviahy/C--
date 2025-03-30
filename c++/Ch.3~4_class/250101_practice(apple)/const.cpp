#include <iostream>
using namespace std;

class FruitSeller
{
private:
    const int APPLE_PRICE; // 사과의 개당 가격 (수정 불가)
    int numOfApple;        // 판매자가 보유한 사과 개수
    int myMoney;           // 판매자가 벌어들인 돈

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
        int num = money / APPLE_PRICE; // 구매자가 살 수 있는 사과 개수 계산
        if (num > numOfApple)
        { // 남아있는 사과보다 많이 요청한 경우
            num = numOfApple;
        }
        numOfApple -= num;             // 판매 후 남은 사과 개수 갱신
        myMoney += num * APPLE_PRICE;  // 판매된 금액만 수익으로 추가
        return num;                    // 실제로 판매된 사과 개수 반환
    }

    void ShowSalesResult() const
    {
        cout << "남은 사과: " << numOfApple << endl;
        cout << "판매 수익: " << myMoney << endl
             << endl;
    }
};

class FruitBuyer
{
private:
    int myMoney;      // 구매자가 보유한 돈
    int numOfApples;  // 구매자가 소유한 사과 개수

public:
    void InitMembers(int money)
    {
        myMoney = money;
        numOfApples = 0;
    }

    void BuyApples(FruitSeller &seller, int money)
    {
        if (money < seller.GetApplePrice())
        { // 최소 1개 가격보다 적으면 실패
            cout << "금액이 부족합니다. 최소 " << seller.GetApplePrice() << "원 이상 입력해 주세요." << endl;
            return;
        }
        if (money > myMoney)
        { // 구매 금액이 보유한 돈보다 클 경우 실패
            cout << "잔액이 부족합니다." << endl;
            return;
        }

        int numToBuy = money / seller.GetApplePrice(); // 구매 가능한 사과 개수 계산
        if (numToBuy < 1)
        { // 1개 이상의 사과를 구매하지 않은 경우
            cout << "1개 이상의 사과를 구매해야 합니다." << endl;
            return;
        }

        int purchasedApples = seller.SaleApples(money);
        if (purchasedApples == 0)
        { // 판매자의 사과가 부족한 경우
            cout << "판매자의 사과가 부족합니다." << endl;
            return;
        }

        numOfApples += purchasedApples;                      // 구매한 사과 개수 추가
        myMoney -= purchasedApples * seller.GetApplePrice(); // 실제 사용된 금액 차감
    }

    void ShowBuyResult() const
    {
        cout << "현재 잔액: " << myMoney << endl;
        cout << "사과 개수: " << numOfApples << endl
             << endl;
    }
};

int main()
{
    FruitSeller seller(1000, 20, 0); // 사과 가격 1000원, 초기 사과 20개, 초기 수익 0원
    FruitBuyer buyer;
    buyer.InitMembers(5000);         // 구매자 초기 자금 5000원

    // 구매 시도
    buyer.BuyApples(seller, 100);    // 100원으로 구매 시도 (실패)
    buyer.BuyApples(seller, 1000);   // 1000원으로 구매 시도 (성공, 1개 구매)
    buyer.BuyApples(seller, 2500);   // 2500원으로 구매 시도 (성공, 2개 구매)

    // 결과 출력
    cout << "과일 판매자의 현황" << endl;
    seller.ShowSalesResult();

    cout << "과일 구매자의 현황" << endl;
    buyer.ShowBuyResult();

    return 0;
}

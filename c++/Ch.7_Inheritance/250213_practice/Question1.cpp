// 294p Question num1

#include <iostream>
using namespace std;

// class에 적당한 생성자를 추가하기
class Car // 가솔린으로 동작하는 자동차
{
private:
    int gasolineGauge;

public:
    Car(int gas)
        : gasolineGauge(gas) {}

    int GetGasGauge()
    {
        return gasolineGauge;
    }
};

class HybridCar : public Car // 가솔린과 전기로 동작하는 자동차
{
private:
    int electricGauge;

public:
    HybridCar(int gas, int elec)
        : Car(gas), electricGauge(elec) {}

    int GetElecGauge()
    {
        return electricGauge;
    }
};

class HybridWaterCar : public HybridCar // 그리고물
{
private:
    int waterGauge;

public:
    HybridWaterCar(int gas, int elec, int water)
        : HybridCar(gas, elec), waterGauge(water) {}

    void showCurrentGauge()
    {
        cout << "Left Gasoline: " << GetGasGauge() << endl;
        cout << "Left Electric Gauge: " << GetElecGauge() << endl;
        cout << "Left Water Gauge: " << waterGauge << endl;
    }
};

// 메인 함수를 적절히 만드는 문제
int main()
{
    HybridWaterCar total(10, 15, 23);
    total.showCurrentGauge();
}
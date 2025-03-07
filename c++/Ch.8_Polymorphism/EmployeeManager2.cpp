// 273p exercise
// 331의 함수 오버라이딩을 통한 다양한 직급 추가

#include <iostream>
#include <cstring>
using namespace std;

class Employee// 추상 클래스
{
private:
    char name[100];

public:
    Employee(char *name)
    {
        strcpy(this->name, name);
    }
    void ShowYourName() const
    {
        cout << "name: " << name << endl;
    }
    virtual int GetPay() const = 0; // 아래와 동일, 명시적으로 몸체를 정의하지 않음
    virtual void ShowSalaryInfo() const = 0; // 추가, 순수 가상함수를 의미
    virtual ~Employee() {}
};

class PermanentWorker : public Employee
{
private:
    // char name[100]; -> Emplyee로 옮김
    int salary; // 월 급여

public:
    PermanentWorker(char *name, int money)
        : Employee(name), salary(money) {}

    int GetPay() const override
    {
        return salary;
    }
    void ShowSalaryInfo() const override
    {
        ShowYourName();
        cout << "salary:" << GetPay() << endl
             << endl;
    }
};

class SalesWorker : public PermanentWorker
{
private:
    int salesResult;   // 월 판매실적
    double bonusRatio; // 상여금 비율

public:
    SalesWorker(char *name, int money, double ratio)
        : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {}

    void AddSalesResult(int value)
    {
        salesResult += value;
    }
    int GetPay() const override
    {
        return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
        // PermanentWorker의 GetPay 함수 호출
    }
    void ShowSalaryInfo() const override
    { // SalesWorker의 GetPay 함수가 호출됨
        ShowYourName();
        cout << "salary: " << GetPay() << endl
             << endl;
    }
};

class TemporaryWorker : public Employee
{
private:
    int workTime;
    int payPerHour;

public:
    TemporaryWorker(char *name, int pay) : Employee(name), workTime(0), payPerHour(pay) {}

    void AddWorkTime(int time) // 일한 시간 추가
    {
        workTime += time;
    }

    int GetPay() const override // 이달 급여
    {
        return workTime * payPerHour;
    }

    void ShowSalaryInfo() const override
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl
             << endl;
    }
};

class EmployeeHandler
{
private:
    Employee *empList[50];
    int empNum;

public:
    EmployeeHandler() : empNum(0) {}

    void AddEmployee(Employee *emp)
    {
        empList[empNum++] = emp;
    }

    void ShowAllSalaryInfo() const 
    { 
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();
    }

    void ShowTotalSalary() const
    {
        int sum = 0; // 지역변수
        for (int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay();

        cout << "salary sum: " << sum << endl;
    }

    ~EmployeeHandler()
    {
        for (int i = 0; i < empNum; i++)
        {
            delete empList[i];
        }
    }
};

int main()
{

    EmployeeHandler handler;

    // 정규직 등록
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("Lee", 1500));

    // 임시직 등록
    TemporaryWorker *alba = new TemporaryWorker("Jung", 700);
    alba->AddWorkTime(5);
    handler.AddEmployee(alba);

    // 영업직 등록
    SalesWorker *seller = new SalesWorker("Hong", 1000, 0.1);
    seller->AddSalesResult(7000); // 영업실적 7000
    handler.AddEmployee(seller);

    // 이번 달에 지불해야 할 급여의 정보
    handler.ShowAllSalaryInfo();

    // 이번 달에 지불해야 할 급여의 총합
    handler.ShowTotalSalary();

    return 0;
}
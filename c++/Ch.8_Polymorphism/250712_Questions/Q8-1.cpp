// 354p 문제 08-1
// 상속 관계의 확장과 추상 클래스
#include <iostream>
#include <cstring>
using namespace std;

class Employee
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
    virtual int GetPay() const
    {
        return 0;
    }
    virtual void ShowSalaryInfo() const {}
};

class PermanentWorker : public Employee
{
private:
    int salary; // 월급여
public:
    PermanentWorker(char *name, int money)
        : Employee(name), salary(money) {}
    int GetPay() const
    {
        return salary;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl
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

enum RISK_LEVEL
{
    RISK_A = 3,
    RISK_B = 2,
    RISK_C = 1
};

class ForeignSalesWorker : public Employee
{
private:
    int salary;
    RISK_LEVEL risk;
    double bonusRatio;

public:
    ForeignSalesWorker(char name[], int salary, double bonusRatio, RISK_LEVEL risk)
        : Employee(name), salary(salary), bonusRatio(bonusRatio), risk(risk) {}

    void AddSalesResult(int performance)
    {
        salary = salary + performance * bonusRatio;
    }
    int GetPay() const override // 이달 급여
    {
        return salary;
    }
    int RiskPay() const
    {
        return salary * risk;
    }

    void ShowSalaryInfo() const override
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl;
        cout << "risk pay: " << RiskPay() << endl;
        cout << "sum: " << GetPay() + RiskPay() << endl
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
        int sum = 0;
        for (int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay();

        cout << "salary sum: " << sum << endl;
    }
    ~EmployeeHandler()
    {
        for (int i = 0; i < empNum; i++)
            delete empList[i];
    }
};

int main()
{
    // 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
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

    // 해외 영업직 등록
    ForeignSalesWorker *fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
    fseller1->AddSalesResult(7000); // 영업실적 7000
    handler.AddEmployee(fseller1);

    ForeignSalesWorker *fseller2 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
    fseller1->AddSalesResult(7000); // 영업실적 7000
    handler.AddEmployee(fseller2);

    ForeignSalesWorker *fseller3 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
    fseller1->AddSalesResult(7000); // 영업실적 7000
    handler.AddEmployee(fseller3);

    // 이번 달에 지불해야 할 급여의 정보
    handler.ShowAllSalaryInfo();
    return 0;
}
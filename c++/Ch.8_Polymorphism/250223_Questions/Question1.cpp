// p354 문제 08-1
// 위험수당 지급 문제

#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
private:
    char name[5];
    int incentive;

protected:
    int salary;

public:
    Employee(char *name, int money, int percent)
        : salary(money), incentive(percent)
    {
        strcpy(this->name, name);
    }

    void AddSalesResult(int performance)
    {
        salary = salary + (performance * incentive);
    }

    virtual int GetPay() const = 0;
    virtual void ShowSalaryInfo() const = 0;
    virtual ~Employee() {} // 이거 왜함?
};

class ForeignSalesWorker : public Employee
{
private:
    int level;

public:
    ForeignSalesWorker(char *name, int salary, int percent, int risk)
        : Employee(name, salary, percent), level(risk)
    {
        level = level * salary;
    }

    void ShowSalaryInfo()
    {
        cout << "name: " << name << endl;
        cout << "salary: " << salary << endl;
        cout << "risk pay: " << level << endl;
        cout << "sum: " << salary + level << endl
             << endl;
    }
};

enum RISK_LEVEL
{
    RISK_A = 1,
    RISK_B = 2,
    RISK_C = 3
};

class EmployeeHandler
{
private:
    ForeignSalesWorker *worker[3];
    int empNum;

public:
    EmployeeHandler() : empNum(0) {}

    void AddEmployee(ForeignSalesWorker *info)
    {
        worker[empNum++] = info;
    }

    void ShowAllSalaryInfo()
    {
        for (int i = 0; i < 3; i++)
        {
            worker[i]->ShowSalaryInfo();
        }
    }
};

int main()
{
    // 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
    EmployeeHandler handler;

    // 해외 영업직 등록
    ForeignSalesWorker *fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
    fseller1->AddSalesResult(7000); // 영업실적 7000
    handler.AddEmployee(fseller1);

    ForeignSalesWorker *fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
    fseller1->AddSalesResult(7000); // 영업실적 7000
    handler.AddEmployee(fseller2);

    ForeignSalesWorker *fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
    fseller1->AddSalesResult(7000); // 영업실적 7000
    handler.AddEmployee(fseller3);

    // 이번 달에 지불해야 할 급여의 정보
    handler.ShowAllSalaryInfo();

    delete fseller1;
    delete fseller2;
    delete fseller3;

    return 0;
}
// 실행은 된다
// printf를 100번써서 별이 100개 나온 기분이다
// ...
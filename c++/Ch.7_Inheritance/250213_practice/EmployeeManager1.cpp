// 273p exercise

#include <iostream>
#include <cstring>
using namespace std;

class PermanentWorker
{
private:
    char name[100];
    int salary;

public:
    PermanentWorker(char *name, int money)
        : salary(money)
    {
        strcpy(this->name, name);
    }
    int GetPay() const
    {
        return salary;
    }
    void ShowSalaryInfo() const
    {
        cout << "name: " << name << endl;
        cout << "salary:" << GetPay() << endl
             << endl;
    }
};

class EmplyeeHandler // 컨트롤 클래스
{
private:
    PermanentWorker *empList[50];
    int empNum;

public:
    void AddEmployee(PermanentWorker *emp)
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
        cout << "salary sum: " << endl;
    }

    ~EmplyeeHandler()
    {
        for (int i = 0; i < empNum; i++)
        {
            delete empList[i];
        }
    }
};

int main()
{
    EmplyeeHandler handler;

    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("Lee", 1500));
    handler.AddEmployee(new PermanentWorker("JUN", 2000));

    handler.ShowAllSalaryInfo();

    handler.ShowTotalSalary();
    return 0;
}

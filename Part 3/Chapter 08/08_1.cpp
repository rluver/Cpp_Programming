#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;



namespace RISK_LEVEL 
{
	enum { RISK_A = 30, RISK_B = 20, RISK_C=  10};
}

class Employee
{
private:
	char name[100];

public:
	Employee(const char* name)
	{
		strcpy(this->name, name);
	}

	void ShowYourName() const
	{
		cout << "name: " << name << endl;
	}

	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;
};

class PermanentWorker : public Employee
{
private:
	int salary;

public:
	PermanentWorker(const char* _name, int _money)
		: Employee(_name), salary(_money)
	{}

	int GetPay() const
	{
		return salary;
	}

	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWorker : public Employee
{
private:
	int workTime;
	int payPerHour;

public:
	TemporaryWorker(const char* _name, int pay)
		: Employee(_name), workTime(0), payPerHour(pay)
	{}

	void AddworkTime(int time)
	{
		workTime += time;
	}

	int GetPay() const
	{
		return workTime * payPerHour;
	}

	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class SalesWorker : public PermanentWorker
{
private:
	int salesResult;
	double bonusRatio;

public:
	SalesWorker(const char* _name, int _money, double _ratio)
		: PermanentWorker(_name, _money), salesResult(0), bonusRatio(_ratio)
	{}

	void AddSalesResult(int value)
	{
		salesResult += value;
	}

	int GetPay() const
	{
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}

	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};


class ForeignSalesWorker : public SalesWorker
{
private:
	int salesResult = 0;
	double riskLevel;

public:
	ForeignSalesWorker(const char* _name, int _money, double _ratio, int _riskLevel)
		: SalesWorker(_name, _money, _ratio), riskLevel(_riskLevel / 100.)
	{}

	int GetRiskPay() const
	{
		return (int)(SalesWorker::GetPay() * (riskLevel));
	}

	int GetPay() const
	{
		return SalesWorker::GetPay() + GetRiskPay();
	}

	void ShowSalaryInfo() const
	{
		SalesWorker::ShowYourName();
		cout << "salary: " << SalesWorker::GetPay() << endl;
		cout << "risk pay: " << GetRiskPay() << endl;
		cout << "sum: " << GetPay() << endl << endl;

	}
};

class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;

public:
	EmployeeHandler() : empNum(0)
	{}

	void AddEmployee(Employee* emp)
	{
		empList[empNum++] = emp;
	}

	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empNum; i++) {
			empList[i]->ShowSalaryInfo();
		}
	}

	void ShowTotalSalary() const
	{
		int sum = 0;
		
		for (int i = 0; i < empNum; i++) {
			sum += empList[i]->GetPay();
		}

		cout << "salary sum: " << sum << endl;
	}

	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++) {
			delete empList[i];
		}
	}
};


int main() {
	EmployeeHandler handler;

	ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	handler.ShowAllSalaryInfo();
}
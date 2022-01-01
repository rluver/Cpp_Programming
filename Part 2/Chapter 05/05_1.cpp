#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

namespace COMP_POS
{
	enum { CLERK, SENIOR, ASSIST, MANAGER };

	void ShowPositionInfo(int position);
}

class NameCard
{
private:
	char* name, * companyName, * phone;
	int position;

public:
	NameCard(const char* name_, const char* companyName_, const char* phone_, int position_)
		: position(position_)
	{
		name = new char[strlen(name_) + 1];
		companyName = new char[strlen(companyName_) + 1];
		phone = new char[strlen(phone_) + 1];

		strcpy(name, name_);
		strcpy(companyName, companyName_);
		strcpy(phone, phone_);
	}

	NameCard(const NameCard& copy)
		: position(copy.position)
	{
		name = new char[strlen(copy.name) + 1];
		companyName = new char[strlen(copy.companyName) + 1];
		phone = new char[strlen(copy.phone) + 1];

		strcpy(name, copy.name);
		strcpy(companyName, copy.companyName);
		strcpy(phone, copy.phone);
	}

	void ShowNameCardInfo();

	~NameCard()
	{
		delete[] name;
		delete[] companyName;
		delete[] phone;
	}
};

void COMP_POS::ShowPositionInfo(int position)
{
	switch (position)
	{
	case CLERK:
		cout << "사원" << endl;
		break;
	case SENIOR:
		cout << "주임" << endl;
		break;
	case ASSIST:
		cout << "대리" << endl;
		break;
	case MANAGER:
		cout << "과장" << endl;
	}
}


// define NameCard function
void NameCard::ShowNameCardInfo()
{
	cout << "이름: " << name << endl;
	cout << "회사: " << companyName << endl;
	cout << "전화번호: " << phone << endl;
	cout << "직급: "; COMP_POS::ShowPositionInfo(position);
	cout << endl;
}



int main()
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSenior;

	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();
}
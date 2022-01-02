#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class MyFriendInfo
{
private:
	char* name;
	int age;
public:
	MyFriendInfo(const char* _name, int _age) : age(_age)
	{
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}

	void showMyFriendInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}

	~MyFriendInfo()
	{
		delete []name;
	}
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char* addr;
	char* phone;
public:
	MyFriendDetailInfo(const char* _name, int _age, const char* _addr, const char* _phone)
		: MyFriendInfo(_name, _age)
	{
		addr = new char[strlen(_addr) + 1];
		phone = new char[strlen(_phone) + 1];
		strcpy(addr, _addr);
		strcpy(phone, _phone);
	}

	void ShowMyFriendDetailInfo() const
	{
		showMyFriendInfo();
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl;
	}

	~MyFriendDetailInfo() 
	{
		delete []addr;
		delete []phone;
	}
};

int main() {
	MyFriendDetailInfo fren1("김진성", 22, "충남 아산", "010-1234-00XX");
	MyFriendDetailInfo fren2("이주성", 19, "경기 인천", "010-3333-00XX");
	fren1.ShowMyFriendDetailInfo();
	fren2.ShowMyFriendDetailInfo();
}
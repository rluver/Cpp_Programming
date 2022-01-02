#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Book 
{
private:
	char* title;
	char* isbn;
	int price;

public:
	Book(const char* _title, const char* _isbn, int _price)
		: price(_price)
	{
		this->title = new char[strlen(_title) + 1];
		this->isbn = new char[strlen(_isbn) + 1];

		strcpy(this->title, _title);		
		strcpy(this->isbn, _isbn);
	}

	void ShowBookInfo() const 
	{
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}

	~Book()
	{
		delete[] title;
		delete[] isbn;
	}
};

class EBook : public Book
{
private:
	char* DRMkey;

public:
	EBook(const char* _title, const char* _isbn, int _price, const char* _DRMkey)
		: Book(_title, _isbn, _price)
	{
		this->DRMkey = new char[strlen(_DRMkey) + 1];
		
		strcpy(this->DRMkey, _DRMkey);
	}

	void ShowEBookInfo() const
	{
		ShowBookInfo();
		cout << "인증키: " << DRMkey << endl;
	}

	~EBook() 
	{
		delete[] DRMkey;
	}
};

int main() {
	Book book("좋은 C++", "555-1234-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;

	EBook ebook("좋은 C++ ebook", "555-1234-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
}
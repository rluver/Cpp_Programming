#include <iostream>

using namespace std;

class Rectangle
{
private:
	int width, length;
public:
	Rectangle(int _width, int _length)
		: width(_width), length(_length) {};

	void ShowAreaInfo() const
	{
		cout << "¸éÀû: " << width * length << endl;
	}
};

class Square : public Rectangle
{
public:
	Square(int _width) : Rectangle(_width, _width) {};
};


int main() {
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
}
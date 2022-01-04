#include <iostream>

using namespace std;

class Point
{
private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{}

	void showPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	Point operator-() {
		Point pos(-xpos, -ypos);
		
		return pos;
	}
};


int main() {
	Point pos1(1, -2);
	(-pos1).showPosition();
}
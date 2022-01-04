#include <iostream>

using namespace std;

class Point
{
private:
	int xpos, ypos;
	
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{}

	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	friend bool operator==(const Point&, const Point&);
	friend bool operator!=(const Point&, const Point&);
};

bool operator==(const Point &pos1, const Point &pos2) 
{
	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
	{
		return true;
	}
	else {
		return false;
	}
}

bool operator!=(const Point& pos1, const Point& pos2)
{
	return !(pos1 == pos2);
}


int main()
{
	Point pos1(20, 30);
	Point pos2(5, 7);

	cout << (pos1 == pos2) << endl;
	cout << (pos1 != pos2) << endl;
}
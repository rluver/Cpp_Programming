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

	friend Point operator-(const Point&);
};

Point operator-(const Point& ref)
{
	Point pos(-ref.xpos, -ref.ypos);

	return pos;
}

int main()
{
	Point pos1(9, -7);
	pos1.ShowPosition();
	Point pos2 = -pos1;
	pos2.ShowPosition();	
}
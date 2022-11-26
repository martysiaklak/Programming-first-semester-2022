#include <iostream>
#include <fstream>
using namespace std;
struct Point {
	int x;
	int y;
	friend istream& operator>>(istream& is, Point& point)
	{
		//cout << "Enter x" << endl;
		is >> point.x;
		//cout << "Enter y" << endl;
		is >> point.y;
		return is;
	}
	friend ostream & operator<<(ostream& os, Point& point)
	{
		os << "x=" << point.x << endl;
		os << "y=" << point.y << endl;
		return os;
	}
};
class Circle {
private:
	Point center;
	int radius;
public:
	Circle() : center(), radius(0) {}
	Circle(Point _center, int radius_) : center(_center), radius(radius_) {}
	Circle(const Circle& circle) : center(circle.center), radius(circle.radius) {}
	friend istream & operator>>(istream & is, Circle & circle)
	{
		//cout << "Enter radius" << endl;
		is >> circle.radius;
		//cout << "Enter center" << endl;
		is >> circle.center;
		return is;
	}
	friend ostream& operator<<(ostream& os, Circle& circle)
	{
		os << "Radius= "<< circle.radius<<endl;
		os << "Center" << endl;
		os <<  circle.center << endl;
		return os;
	}
};
int main()
{
	Circle circle;
	//cout << "¬вед≥ть дан≥ про коло" << endl;
	//cin >> circle; //operator >> (cin, circle)
	//cout << circle;
	ifstream ifs;
	ofstream ofs("result.txt");
	ifs.open("data.txt");
	ifs >> circle;
	ifs.close();
	ofs << circle;
	ofs.close();
	return 0;
}
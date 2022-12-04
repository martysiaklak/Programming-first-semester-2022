#include <iostream>
#include <fstream>
#include <math.h>
# define M_PI   3.14159265358979323846 
using namespace std;
struct Point {
	int x;
	int y;
	friend istream& operator>>(istream& is, Point& point)
	{
		cout << "Enter x" << endl;
		is >> point.x;
		cout << "Enter y" << endl;
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
		cout << "Enter radius" << endl;
		is >> circle.radius;                    
		cout << "Enter center" << endl;
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
	bool operator<(const Circle& circle2)
	{
		return S() < circle2.S();
	}
	bool operator>(const Circle& circle2)
	{
		return S() > circle2.S();
	}
	double S()  const       //calculating square
	{
		double S1 = M_PI * pow(radius, 2);
		return S1;
	}
	double C()
	{
		double C = M_PI * 2 * radius;
		return C;
	}
	bool intersecting(const Circle& circle2)
	{
		double d = sqrt((center.x - circle2.center.x) * (center.x - circle2.center.x) + (center.y - circle2.center.y) * (center.y - circle2.center.y));
		if (d < abs(radius - circle2.radius))
		{
			return false;
		}
		if (d <= radius + circle2.radius)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
};
void sort(Circle* array);
int main()
{
	Circle array[10];
	for (int i = 0; i < 10; i++)
	{
		cout << "Data about circle " << i<<endl;
		cin >> array[i];
	}
	sort(array);
	for (int i = 0; i < 10; i++)
	{
		cout << array[i].S()<<endl;
	}
	cout << "Enter circle" << endl;
	Circle circle;
	cin >> circle;
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		if (array[i].intersecting(circle) == true)  
		{
			sum += 1;
		}
	}
	cout << "sum= "<<sum;
	/*ifstream ifs;
	ofstream ofs("result.txt");
	ifs.open("data.txt");
	ifs >> circle;
	ifs.close();
	ofs << circle;
	ofs.close();*/
	return 0;
}
void sort(Circle* array)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (array[i] < array[j])
			{
				Circle temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

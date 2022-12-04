#include <iostream> 
using namespace std;
struct Point
{
	float x, y;

	friend ostream& operator<<(ostream& os, Point point)
	{
		os << "x: " << point.x << endl;
		os << "y: " << point.y << endl;


			//���� ���� ��'�����, �� �� + � -. ����� if
		/*os << "a= " << line_.a << endl;
		os << "b= " << line_.b << endl;
		os << "c= " << line_.c << endl;*/
		return os;
	}
};
class line {
private:
	float a, b, c;
public:
	line() : a(), b(), c() {}
	line(const line& line) : a(line.a), b(line.b), c(line.c) {}
	friend istream& operator>>(istream& is, line& line_)
	{
		cout << "Enter a" << endl;
		is >> line_.a;
		cout << "Enter b" << endl;
		is >> line_.b;
		cout << "Enter c" << endl;
		is >> line_.c;
		return is;
	}
	friend ostream& operator<<(ostream& os, line line_)
	{
		os << line_.a << 'x' << '+' << line_.b << 'y' << '+' << line_.c << "=0";
		//���� ���� ��'�����, �� �� + � -. ����� if
		/*os << "a= " << line_.a << endl;
		os << "b= " << line_.b << endl;
		os << "c= " << line_.c << endl;*/
		return os;
	}
	Point getInterception(line &line_)
	{
		float bottom = a * line_.b - b * line_.a;
		
		float x = (b * line_.c - line_.b * c) / bottom;
		float y = (c * line_.a - line_.c * a) / bottom;
		Point p;
		p.x = x;
		p.y = y;
		return p;
	}

	bool isIntercepting(line& line_)
	{
		float bottom = a * line_.b - b * line_.a;

		if (bottom == 0)
		{
			return false;
		}
		else {
			return true;
		}
	}
	float getAngle(line & line2) 
	{
		double angle = (line2.a * a + line2.b * b) / (sqrt(line2.a * line2.a + line2.b * line2.b) * sqrt(a * a + b * b);
		return angle;
	}
	bool isonline(Point& line3)
	{
		if (a* line3.x + b * line3.y + c == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
	int main()
	{
		line line[10];
		for (int i = 0; i < 10; i++)
		{
			cin >> line[i];
		}
		for (int i = 0; i < 10; i++)
		{
			for (int j = i+1; j< 9; j++)
			{
				if (line[i].isIntercepting(line[j]) == true)
				{
					cout << "line " <<line[i]<<"peretenaitsa z " <<line[j] << endl;
					cout << "point of interseption is " << line[i].getInterception(line[j]) << endl;
				}
			}
		}

		/*line line, line;
		cout << "Data about line" << endl;
		operator >> (cin, line);
		cout << "Data about line2" << endl;
		operator >> (cin, line2);
		cout << line;
		cout << line2;
		if (line.isIntercepting(line2) == false)
		{
			cout << "Paralelni" << endl;
		}
		else
		{
			cout << line.getInterception(line2).x<< line.getInterception(line2).y;
		}
		return 0;*/
	}

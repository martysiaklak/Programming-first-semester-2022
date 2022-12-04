#include <iostream>
using namespace std;       //розібратися з файлом
struct Point               //зробити якщо в одній лінії то нема
{
	int x, y;
	friend istream& operator>>(istream& is, Point& point)
	{
		cout << "Enter x: ";
		is >> point.x;
		cout << "Enter y: ";
		is >> point.y;
		return is;
	}
	friend ostream& operator<<(ostream& os, Point& point)
	{
		os << "(" << point.x << ", " << point.y << ")" << endl;
		return os;
	}
};
class Quad
{
private:
	Point a, b, c, d;
public:
	Quad(): a(), b(), c(), d(){}
	Quad(const Quad& quad): a(quad.a), b(quad.b), c(quad.c), d(quad.d){}
	friend istream& operator>>(istream& is, Quad& quad)
	{
		cout << "Enter a" << endl;
		is >> quad.a;
		cout << "Enter b" << endl;
		is >> quad.b;
		cout << "Enter c" << endl;
		is >> quad.c;
		cout << "Enter d" << endl;
		is >> quad.d;
		return is;
	}
	friend ostream& operator<<(ostream& os, Quad& quad)
	{
		os << "a:" << quad.a <<endl;
		os << "b:" << quad.b << endl;
		os << "c:" << quad.c << endl;
		os << "d:" << quad.d << endl;
		os << "--------------" << endl;
		return os;
	}
	double length_of_1() const
	{
		double l = sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
		return l;
	}
	double length_of_2() const
	{
		double l = sqrt(pow((b.x - c.x), 2) + pow((b.y - c.y), 2));
		return l;
	}
	double length_of_3() const
	{
		double l = sqrt(pow((c.x - d.x), 2) + pow((c.y - d.y), 2));
		return l;
	}
	double length_of_4() const
	{
		double l = sqrt(pow((d.x - a.x), 2) + pow((d.y - a.y), 2));
		return l;
	}
	double P() const
	{
		double P = length_of_1() + length_of_2() + length_of_3() + length_of_4();
		return P;
	}
	bool is_square()
	{
		if (length_of_1() == length_of_2() && length_of_2() == length_of_3() && length_of_3() == length_of_4())
		{
			return true;
		}
	}
	bool is_rectangle()
	{
		if (length_of_1() == length_of_3() && length_of_2() == length_of_4())
		{
			return true;
		}
	}
	bool operator<(const Quad& quad2)
	{
		return P() < quad2.P();
	}
};
void sort(Quad* array);
int main()
{
	Quad array[2];
	for (int i = 0; i < 2; i++)
	{
		cout << "Quad " << i << endl;
		cin >> array[i];
	}
	sort(array);
	for (int i = 0; i < 2; i++)
	{
		cout << array[i].P()<<endl;
	}
	cout << "--------------" << endl;
	cout << "Quads that are squares:" << endl;
	for (int i = 0; i < 2; i++)
	{
		if (array[i].is_square() == true)
		{
			cout << "Quad " << i << ":" << endl;
			cout << array[i];
		}
	}
	cout << "--------------" << endl;
	cout << "Quads that are rectangles:" << endl;
	for (int i = 0; i < 2; i++)
	{
		if (array[i].is_rectangle() == true)
		{
			cout << "Quad " << i << ":" << endl;
			cout << array[i];
		}
	}
	return 0;
}
void sort(Quad* array)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = i + 1; j < 2; j++)
		{
			if (array[i] < array[j])
			{
				Quad temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}
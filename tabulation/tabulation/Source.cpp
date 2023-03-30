#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
ostringstream Tab(double(*f)(double), double a, double b, int n)
{
	ostringstream os;
	os << '|' << setw(5) << "x" << setw(5) << '|' << setw(5) << "sinx" << setw(5) << '|' << endl;
	int h = (b - a) / n;
	for (a; a < b; a + h)
	{
	os<<'|'<< setw(5) << "a" << setw(5) << '|' << setw(5) << f(a) << setw(5) << '|' << endl;
	}
	return os;
}
int main()
{
	double a, b;
	int n;
	cout << "Enter line a, b and atep n" << endl;
	cin >> a >> b >> n;
	ostringstream st;
	st = Tab(sin, a, b, n);
	ofstream file1("result.txt");
	file1 << "sinx" << endl << st;
	double f1(double x)
	{
		double result;
		result = pow(x, 3) + pow(x, 2) - 8 * x + 9;
		return result;
	}
	st1 = Tab(f1, a, b, n) :
		file << "x^3+x^2-8x+9" << endl << st1;
	st2 = Tb([](double x)) { return sin(x) + 8 * tan(x) - 24 * pow(x, 2); }
	file << "sinx+8tgx-24*x^2" << endl << st2;
	return 0;
}
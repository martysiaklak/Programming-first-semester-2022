#include <iostream>
#include<string>
#include<math.h>
# define M_PI           3.14159265358979323846
using namespace std;
int main()
{
	double radius;
	double C;
	double S;
	double V;
	//asking for entering a radius
	cout << "Enter a radius:";
	//remembering a variable
	cin >> radius;
	//counting a circumference
	C = 2 * radius * M_PI;
	//printing it
	cout << "Circumference="<<C<<endl;
	//calculating an area of a circle
	S = M_PI * pow(radius,2);
	//printing it
	cout << "Area of a circle=" << S << endl;
	//calculating a volume of a sphere   is V = 4/3 πr³.
	V= 4.0/3* M_PI * pow(radius, 3);
	//printing it
	cout << "Volume of a sphere=" << V << endl;

		return 0;
}




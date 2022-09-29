#include <iostream>
#include<math.h>
using namespace std;
int main()
{
	int a;
	int b;
	float am; //arithmetic mean
	float gm; //geometric mean

	cout << "Enter the first number(a positive integer):";
	cin >> a;
	cout << "Enter the second number(a positive integer):";
	cin >> b;

	/* solution ¹1:
	am = (static_cast<float>(a) + static_cast<float>(b)) / 2;
	cout << "Arithmetic mean=" << am<<endl;*/
	cout << "Arithmetic mean="<< (static_cast<float>(a) + static_cast<float>(b)) / 2<<endl;

	gm = sqrt(static_cast<float>(a) * static_cast<float>(b));
	cout << "Geometric mean=" << gm;
	
	return 0;
}



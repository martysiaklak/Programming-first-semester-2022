#include <iostream>
#include <math.h>
using namespace std;
int n1, n2, n3;
int main()
{   //asking for input
	cout << "Enter the first number(n � N):";
	cin >> n1;
	cout << "Enter the second number(n � N):";
	cin >> n2;
	cout << "Enter the third number(n � N):";
	cin >> n3;
			if (n2 - n1 == n3 - n2)          //checking
		{
			cout << "It's an arithmetic progression";    //outputing the result
		}
		else
		{
			cout << "It's not an arithmetic progression";
		}
			return 0;
}
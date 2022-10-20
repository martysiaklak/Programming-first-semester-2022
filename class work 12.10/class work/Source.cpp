#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	/* Ñelsium
	for (int i = 0; i <= 100; i++)
	{
		cout << i << "C " << 9.0 / 5 * i + 32 << "F " << endl;
	}
	*/

	/* pow(4, k) < m
	int m, k = 0;
	cout << "Enter a number m:";
	cin >> m;
	if (m > 1)
	{
		while (pow(4, k) < m)
		{
			k++;
		}
		cout << "k:" << k - 1<<endl;
		cout << pow(4, k - 1)<<endl;
		cout << pow(4, k) << endl;

	}
	else
	{
		cout << "Error";
	}*/

	/*Fibonachi
	int n, u0 = 0, u1 = 1, u;
	cout << "Enter n:";
	cin >> n;
	cout << u0 << endl;
	cout << u1<< endl;
	for (int i = 2; i <= n; i++)
	{
		u = u0 + u1;
		cout << u<<endl;
		u0 = u1;
		u1 = u;
	}*/

	//àëãîðèòì åâêë³äà
	int n, m;
	cout << "Enter n:" << endl;
	cin >> n;
	cout << "Enter m:" << endl;
	cin >> m;

	// check if numbers are valid
	if (n <= 0 || m <= 0)
	{
		cout << "Invalid input. Please enter positive integers." << endl;
		return -1;
	}

	// calculate the greatest common divisor 
	while (n != m)
	{
		if (n > m)
		{
			n = n - m;
		}
		else 
		{
			m = m - n;
		}
		
	}

	// output the results
	cout << "The greatest common divisor is: " << n << endl;
	
	return 0;
}
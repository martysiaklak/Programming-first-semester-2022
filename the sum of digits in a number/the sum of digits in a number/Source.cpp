#include <iostream>
using namespace std;
int n, m;
int sum = 0;
int main()
{    //asking for input
	cout << "Enter a three-digit number:";
		cin >> n;
	while(n>0)
		{
		m = n % 10;        //getting the last digit
		sum = sum + m;     //adding it to the sum
		n = n / 10;        //remove last digit from number
		}
	cout << "Sum=" << sum; //printing the result

}
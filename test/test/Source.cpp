#include <iostream>
#include <math.h>
using namespace std;
/*int main() //sum of digits
{
	float x;
	int digit;
	int sum = 0;
	cout << "Enter x:" << endl;
	cin >> x;
	int n = abs(x);
	while (n >0)
	{
		digit = n % 10;
		sum = sum + digit;
		n = n / 10;
	}
	cout << "Sum:" << sum << endl;
	return 0;
}*/

/*int main() //min number of an array(taking only positive numbers)
{
	float array[15];
	for (int i = 0; i < 15; i++)
	{
		cout << "Enter " << i+1 << " number" << endl;
		cin >> array[i];
		if (array[i] <= 0) //if a number is <=0 we ask for it one more time
		{
			cout << "Error"<<endl;
			i--;
		}
	}
	float min = array[0];

	for (int i = 1; i < 15; i++) //looking for a min number
	{
		if (array[i] < min)
		{
			min = array[i];
		}
	}
	cout << "min=" << min;
	return 0;
}*/

/*int main() //min positive element of an array
{
	float array[15];
	int sum = 0;
	for (int i = 0; i < 15; i++)
	{
		cout << "Enter " << i+1 << " number: " << endl;
		cin >> array[i];
	}

	float min;
	for (int i = 0; i < 15; i++) //the first positive number will be min
	{
		if (array[i] > 0)
		{
			min = (float)array[i];
			break;
		}
	}

	for (int i = 0; i < 15; i++)  //looking for a real min number
	{
		if (array[i] > 0 && array[i] <= min)
		{
			min = (float)array[i];
		}
		if (array[i] <= 0) //checking if an array has at least one positive number
		{
			sum++;
		}
	}
	if (sum == 15) //if no printing error
	{
		cout << "Error, your array must contain at least 1 positive number";
		exit(0);
	}
	cout << "min=" << min;
	return 0;
}*/

int main() //checking if date is valid
{
	unsigned d, m, y;
	cout << "Enter day, mounth and year: " << endl;
    cin >> d >>m >>y;
	if (d > 0 && d < 32 && m>0 && m < 12 && y>0)
	{
		switch (m)
		{
		case 4:
		case 6:
		case 9:
		case 11:
			if (d <= 30)
			{
				cout << d << "/" << m << "/" << y;
			}
			else
			{
				cout << "Invalid date";
			}
			break;

		case 2:
			if (d <= 28)
			{
				cout << d << "/" << m << "/" << y;
			}
			else
			{
				cout << "Invalid date";
			}
			break;

		default:
				if (d <= 31)
				{
					cout << d <<"/" << m << "/" << y;
				}
				else
				{
				cout << "Invalid date";
				}
				break;
		}
	}
	else
	{
		cout << "Invalid date" << endl;
	}
	return 0;
}
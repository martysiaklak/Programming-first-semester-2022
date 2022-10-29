#include <iostream>
#include <math.h>
using namespace std;
/*int main()
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

int main()
{
	float array[15];
	for (int i = 0; i < 15; i++)
	{
		cout << "Enter " << i << " number" << endl;
		cin >> array[i];
	}
	float min = 0;
	for (int i = 0; i < 15; i++)
	{
		if (array[i] > 0)
		{
			min = (float)array[i];
			break;
		}
	}

	for (int i = 0; i < 15; i++)
	{
		if (array[i] > 0 && array[i] <= min)
		{
			min = (float)array[i];
		}
	}
	cout << "min=" << min;
	return 0;
}
int main()
{
	int d, m, y;
	cin >> d >> m >> y;
	if (d > 0 && d < 32 && m>0 && m < 12 && y>0)
	{
		switch(m)
			case 4:
			case 6:
			case 9:
			case 11:
				if (d <= 30)
				{
					cout << "ok";
					break;
				}
				
			case 2:
				if (d <= 28)
				{
					cout << "ok";
					break;
				}
			default:
				if(d<=31)
	}

	return 0;
}
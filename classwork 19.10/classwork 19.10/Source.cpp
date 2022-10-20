#include <iostream>
using namespace std;
/*int main()
{
	double a[100];
	int n;
	cout << "Enter n:";
	cin >> n;
	cout << "Numbers:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	double S = a[0];
	double b[100];
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i] / (1 + S * S);
		S = S + a[i + 1];
		cout << b[i]<<endl;
	}

		return 0;
}*/
/*int main()
{
	cout << "Enter k:";
	int k;
	cin >> k;
	for (int i = 1; i <= k; i++)
	{
		if (k % i == 0)
		{
			cout << i<<endl;
		}
	}
	return 0;
}*/
/*int main()
{
	double a[100];
	cout << "Enter m:";
	int m;
	cin >> m;
	cout << "Numbers:" << endl;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}
	bool s = true;
	for (int i = 0; i < m-1; i++)
	{
		if (a[i] < a[i + 1])
		{
			cout << "Error";
		    s = false;
			break;
		}
	}
	if (s == true)
	{
		cout << "Spadna";
	}
	return 0;
}*/
int main()
{
	int size;
	cout << "Input size:";
	cin >> size;
	int array[100];
	for (int i = 0; i < size; i++)
	{
		cout << "Input x" << i << endl;
		cin >> array[i];
	}
	int min = array[0];
	int index = 0;
	for (int i = 1; i < size; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
			index = i;
		}
	
	}
	cout << "minimum=" << min << endl;
	cout<< "Index=" << index;

}
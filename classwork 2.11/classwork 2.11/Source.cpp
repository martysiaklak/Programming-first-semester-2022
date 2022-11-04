#include <iostream>
using namespace std;
int main()
{
	int size_1, size_2;
	//getiing a first array(already sorted in ascending order)
	cout << "Enter size 1: ";
	cin >> size_1;
	int* a = new int[size_1];
	for (int i = 0; i < size_1; i++)
	{
		cout << "Enter " << i + 1 << ": ";
		cin >> a[i];
	}

	//getting a second array(already sorted in ascending order)
	cout << "Enter size 2: ";
	cin >> size_2;
	int* b = new int[size_2];
	for (int i = 0; i < size_2; i++)
	{
		cout << "Enter " << i + 1<<": ";
		cin >> b[i];
	}
	
	//creating a third one(in ascending order)
	int i = 0; 
	int j = 0; 
	int k = 0;
	int* c = new int[size_1 + size_2];
	while (i < size_1 && j < size_2)
	{
		if (a[i] < b[j])
		{
			c[k] = a[i];
			i++;
			k++;
		}
		else if (a[i] > b[j])
		{
			c[k] = b[j];
			j++;
			k++;
		}
		else if (a[i] == b[j])
		{
			c[k] = b[j];
			j++;
			k++;
			c[k] = a[i];
			i++;
			k++;
		}
	}

	while (i < size_1) //in case a previous loop didin't take all the elements
	{
		c[k] = a[i];
		i++;
		k++;
	}
	while (j < size_2)
	{
		c[k] = b[j];
		j++;
		k++;
	}

	for (int k = 0; k < size_1 + size_2; k++) //outputting results(a third array)
	{
		cout << c[k] << endl;
	}
	return 0;
}
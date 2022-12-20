#include<iostream>
#include <math.h>;
using namespace std;
int count_sum(float* array, int size);
void change_elements(float* array, int size);
int main() 
{
	int n, m;
	cout << "Enter a size of first array:" << endl;
	cin >> n;
	float* x = new float[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Enter " << i + 1 << ":" << endl;
		cin >> x[i];
	}
	int sum_x = count_sum(x, n);

	cout << "Enter a size of a second array:" << endl;
	cin >> m;
	float* y = new float[m];
	for (int i = 0; i < m; i++)
	{
		cout << "Enter " << i + 1 << ":" << endl;
		cin >> y[i];
	}
	int sum_y = count_sum(y, m);

	if (sum_x == 0 && sum_y == 0)
	{
		cout << "There are no negative numbers in any array" << endl;
		exit(0);
	}
	 
	if (sum_x > sum_y)
	{
		change_elements(x, n);
		cout << "elements of the first array in ^3:" << endl;
		for (int i = 0; i < n; i++)
		{
			cout <<x[i]<<endl;
		}
	}
	else if (sum_x < sum_y)
	{
		change_elements(y, m);
		cout << "elements of the second array in ^3:" << endl;
		for (int i = 0; i < m; i++)
		{
			cout << y[i] << endl;
		}
	}
	else if (sum_x == sum_y)
	{
		cout << "sum is the same, error" << endl;
	}
	return 0;
}
int count_sum(float* array, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] < 0)
		{
			sum++;
		}
	}
	return sum;
}
void change_elements(float* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = pow(array[i], 3);
	}
}

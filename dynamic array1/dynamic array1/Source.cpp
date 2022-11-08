#include <iostream>
using namespace std;
int main()
{
	cout << "Enter size:";
	int size;
	cin >> size;
	int * array = new int[size];
	int sum = 0;
	int sum_negative = 0;
	int sum_of_negative = 0;
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter " << i + 1 << ":" << endl;
		cin >> array[i];
		if (array[i] > 0) //how many positive numbers are there in an array
		{
			sum++;
		}
		if (array[i] < 0)
		{
			sum_negative++;    //how many negative numbers are there in an array
			sum_of_negative = sum_of_negative + array[i];  //a sum of negative numbers
		}
		cout << endl;
	}
	int * new_array = new int[sum];
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] > 0)
		{
			new_array[k] = array[i]; //creating a new array, which contains of only positive numbers
			k++;
		}
	}
	if (sum == 0)
	{
		cout << "There are no positive elements in your array" << endl;
	}
	else
	{
		cout << "New array(only positive numbers):" << endl;
		for (int k = 0; k < sum; k++)
		{
			cout << new_array[k] << endl;
		}
	}
	cout << endl;

	if (sum_negative == 0)
	{
		cout << "There are no negative elements in your array" << endl;
	}
	else
	{
		cout << "A sum of negative elements in your array:" << sum_of_negative << endl;
	}
	cout << endl;
	int min = array[0];
	int max = array[0];
	int* qmin = array;
	int* qmax = array;
	for (int i = 0; i < size; i++) //min number switches with max and vice versa
	{
		if (array[i] < min)
		{
			min = array[i];
			qmin = &array[i];
		}
		if (array[i] > max)
		{
			max = array[i];
			qmax = &array[i];
		}
	}
	*qmin = max;
	*qmax = min;
	cout << "New array(max and min elements are switched):" << endl;
	for (int i = 0; i < size; i++)
	{
		cout<<array[i]<<endl;
		
	}
	return 0;
}
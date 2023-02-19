#include <iostream>
using namespace std;
void Sort(int* array, int size);
int main()
{
	int size;
	cout << "Enter size:" << endl;
	cin >> size;
	int* array = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Enter " << i + 1 << ":" << endl;
		cin >> array[i];
	}
	Sort(array, size);
	for (int i = 0; i < size; i++)
	{
		cout << array[i];
	}
	return 0;
}
void Sort(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (array[i] > array[j])
			{
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}
/* void Sort(int* array, int size)
{
for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size-i-1; j++)
		{
			if (array[j] > array[j+1])
			{
				swap(array[j], array[j+1]);
			}
		}
	}
}*/               //розібрати
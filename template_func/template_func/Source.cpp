#include <iostream>
using namespace std;

template<typename T>
int unique(T* array, int size, int i)
{
	int quantity = 0;
	for (int j = 0; j < size; j++)
	{
		if (array[j] != array[i])
		{
			quantity++;
		}
		else if (array[j] == array[i])
		{
			continue;
		}
	}
	return quantity;
}
int main()
{
	try
	{
		cout << "enter size of int array: " << endl;
		int size_int;
		cin >> size_int;
		int* int_arr = new int[size_int];
		for (int t = 0; t < size_int; t++)
		{
			cout << "Enter element " << t << endl;
			cin >> int_arr[t];
		}
		int num;
		cout << "number of what element do you choose?" << endl;
		cin >> num;
		if (num!=int(num))  //якщо i не інтове
		{
			throw invalid_argument("Wrong data type");  
		}
		int test_sum=0;
		for (int t = 0; t < size_int; t++)
		{
			if (num == t)
			{
				test_sum++;
			}
		}
		if (test_sum ==0) 
		{
			throw out_of_range("There is no element with that number");
		}
		cout << "quantity of elemnts different from el " << num << ": " << unique(int_arr, size_int, num) << endl;
		cout << "enter size of string array: " << endl;
		int size_str;
		cin >> size_str;
		string* string_arr = new string[size_str];
		for (int t = 0; t < size_str; t++)
		{
			cout << "Enter element " << t << endl;
			cin >> string_arr[t];
		}
		int num_str;
		cout << "number of what element do you choose?" << endl;
		cin >> num_str;
		if (num_str != int(num_str))  //якщо i не інтове
		{
			throw invalid_argument("Wrong data type");
		}
		int test_sum_str = 0;
		for (int t = 0; t < size_str; t++)
		{
			if (num_str == t)
			{
				test_sum_str++;
			}
		}
		if (test_sum_str == 0)
		{
			throw out_of_range("There is no element with that number");
		}
		cout << "quantity of elemnts different from el " << num_str << ": " << unique(string_arr, size_str, num_str) << endl;
	}
	catch (invalid_argument e)
	{
		cerr << "Error:" << e.what() << endl;
	}
	catch (out_of_range e)
	{
		cerr << "Error:" << e.what() << endl;
	}
}
//Визначити шаблонну функцію, 
//яка підраховує кількість елементів,
//відмінних від вказаного i-го елемента в масиві.
//Передбачити перехоплення винятків при невірному значенні i.
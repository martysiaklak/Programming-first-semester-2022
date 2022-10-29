#include <iostream>
using namespace std;
int main()
{
	int n, m;
	cout << "Enter the number of rows:" << endl;
	cin >> m;
	cout << "Enter the number of colunms:" << endl;
	cin >> n;
	float array[300][300];

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Enter(" << i << "," << j <<")";
			cin >> array[i][j];
		}
	}
	cout << endl;

	//matrix output
	cout << "Matrix:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << array[i][j]<<" ";
		}
		cout << endl;
	}

	cout << endl;

//odd number columns
	cout << "Columns of odd numbers:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j % 2 == 1)
			{
				cout << array[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl;

	//first diagonal
	cout << "first diagonal:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				cout << array[i][i] << " ";
			}
		}
	}

	cout << endl;

	//second diagonal
	cout << "second diagonal:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i +j)==(m-1))
			{
				cout << array[i][j]<<" "; 
			}
		}
	}
	cout << endl;
	cout << endl;

	/*another option of outputting diagonals
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i==j || (i +j)==(m-1))
			{
				cout << array[i][j]; 
			}
			else
			{
				cout << " ";
			}
		}
		cout<<endl;
	*/
	

	//looking for a minimum number in each row
	for (int i = 0; i < m; i++)
	{
		int min = array[i][0];
		for (int j = 0; j < n; j++)
		{
				if (array[i][j] < min)
				{
					min = array[i][j];
				}
		}
		cout << "The smallest number in a row " << i << ": " << min << endl;
	}
	cout << endl;

	//swapping two rows
	int k, l;
	cout << "Enter k:" << endl;
	cin >> k;
	cout << "Enter l:" << endl;
	cin >> l;
	float temp;
		for (int j = 0; j < n; j++)
		{
			temp = array[k][j];
			array[k][j]=array[l][j];
			array[l][j] = temp;
		}
		cout << "Your new matrix:" << endl;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << array[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		//getting a number of columns, whose elements are descending
		int descendingColumns = 0;
		for (int j = 0; j < n; j++)
		{
			bool isDescending = true;
			for (int i = 1; i < m; i++)
			{
				if (array[i][j] >= array[i - 1][j])
				{
					isDescending = false;
					break;
				}
			}

			if (isDescending)
			{
				descendingColumns++;
			}
		}
		
		cout << "Number of columns where elements are descending: " << descendingColumns << endl;



	return 0;
}
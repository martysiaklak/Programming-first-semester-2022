#include <iostream>
using namespace std;
int counting_s(int l, int r);
int main()
{
	cout << "Enter size" << endl;
	int size;
	cin >> size;
	float * array = new float [size];
	for (int i = 0; i < size; i++)
	{
		cout << "Enter " << i + 1 << ": " << endl;
		cin >> array[i];
	}
	for (int i = 1; i < size; i++)
	{
		int b = array[i];
		int l = 1;
		int r = i - 1;
		int s;
		s = counting_s(l, r);
		while (r >= l)
		{
			if (b > array[s])
			{
					l = s + 1;
					s = counting_s(l, r);
			}
			else if (b < array[s])
			{
				r = s;
				s = counting_s(l, r);
			}
		}
	}
	
	return 0;
}
int counting_s(int l, int r)
{
	int s;
	s = int((l + r) / 2);
	return s;
}
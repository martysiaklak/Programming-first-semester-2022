#include <iostream>
using namespace std;
int main()
{
	int n, m;
	cout << "Enter the number of rows:" << endl;
	cin >> m;
	cout << "Enter the number of colunms:" << endl;
	cin >> n;
	if (m % 1 == 0 || n % 1 == 0)
	{
		cout << "yes" << endl;
	}
	//if (m == int(m) || n == int(n))
	//{
	//	cout << "yes" << endl;
	//}

	//float array[][];
	return 0;
}
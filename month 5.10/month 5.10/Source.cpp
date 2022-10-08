#include <iostream>
using namespace std;
int number;
int main()
{
	cout << "Enter the number of a month:";
	cin >> number;
	switch (number)
	{
	case 1:
		cout << "January" << endl;
		break;
	case 2:
		cout << "Fabruary" << endl;
		break;
	case 3:
		cout << "March" << endl;
		break;
	case 4:
		cout << "April" << endl;
		break;
	case 5:
		cout << "May" << endl;
		break;
	case 6:
		cout << "June" << endl;
		break;
	case 7:
		cout << "July" << endl;
		break;
	case 8:
		cout << "August" << endl;
		break;
	case 9:
		cout << "September" << endl;
		break;
	case 10:
		cout << "October" << endl;
		break;
	case 11:
		cout << "November" << endl;
		break;
	case 12:
		cout << "December" << endl;
		break;
	default:
		cout << "Invalid number" << endl;
	}
	return 0;
}
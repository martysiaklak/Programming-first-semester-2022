#include <iostream>
using namespace std;
int d, m;
int main()
{   //asking for input
	cout << "Enter a day of your birth:";
	cin >> d;
	cout << "Enter a month of your birth(number):";
	cin >> m;
	if ((m == 3 && d > 20) || (m == 4 && d < 21))     //checking the sign
	{
		cout << "Aries";
	}
	if ((m == 4 && d > 20) || (m == 5 && d < 22))
	{
		cout << "Taurus";
	}
	if ((m == 5 && d > 21) || (m == 6 && d < 22))
	{
		cout << "Gemini";
	}
	if ((m == 6 && d > 21) || (m == 7 && d < 23))
	{
		cout << "Cancer";
	}
	if ((m == 7 && d > 22) || (m == 8 && d < 22))
	{
		cout << "Leo";
	}
	if ((m == 8 && d > 21) || (m == 9 && d < 24))
	{
		cout << "Virgo";
	}
	if ((m == 9 && d > 23) || (m == 10 && d < 24))
	{
		cout << "Libra";
	}
	if ((m == 10 && d > 23) || (m == 11 && d < 23))
	{
		cout << "Scorpio";
	}
	if ((m == 11 && d > 22) || (m == 12 && d < 23))
	{
		cout << "Sagittarius";
	}
	if ((m == 12 && d > 22) || (m == 1 && d < 23))
	{
		cout << "Capricorn";
	}
	if ((m == 1 && d > 20) || (m == 2 && d < 20))
	{
		cout << "Aquarius";
	}
	if ((m == 2 && d > 19) || (m == 3 && d < 21))
	{
		cout << "Pisces";
	}
	return 0;
}
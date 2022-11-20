#include <iostream>
#include<algorithm>
using namespace std;
enum days 
{
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY,
	NOTHING
};
days from_string(string input);
int quantity(days* array, int size, days MONDAY);
string from_days(days MONDAY);
int main()
{
	//string day;
	int size;
	/*cout << "Enter a day:" << endl;
	cin >> day;*/
	cout << "Enter size:" << endl;
	cin >> size;
	string* array_days = new string[size];
	days* day_of_week = new days[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Enter " << i + 1 << ": " << endl;
		cin >> array_days[i];
		day_of_week[i] = from_string(array_days[i]);

	}
	sort(day_of_week, day_of_week + size);
	for (int i = 0; i < size; i++)
	{
		int sum=quantity(day_of_week, size, day_of_week[i]);
		string output = from_days(day_of_week[i]);
		cout << output << "-->" << sum << "times" << endl;
	}

	return 0;
}
days from_string(string input)
{
	for (int i = 0; i < input.size(); i++)
	{
		input[i] = toupper(input[i]);
	}
	if (input == "MONDAY")
	{
		return MONDAY;
	}
	if (input == "TUESDAY")                  
	{
		return TUESDAY;
	}
	if (input == "WEDNESDAY")
	{
		return 	WEDNESDAY;
	}
	if (input == "THURSDAY")
	{
		return 	THURSDAY;
	}
	if (input == "FRIDAY")
	{
		return FRIDAY;
	}
	if (input == "SATURDAY")
	{
		return SATURDAY;
	}
	if (input == "SUNDAY")
	{
		return SUNDAY;
	}
	else
	{
		return NOTHING;
	}

}
string from_days(days MONDAY)
{
	if (MONDAY == 0)
	{
		return "MONDAY";
	}
	if (MONDAY == 1)
	{
		return "TUESDAY";
	}
	if (MONDAY == 2)
	{
		return 	"WEDNESDAY";
	}
	if (MONDAY == 3)
	{
		return 	"THURSDAY";
	}
	if (MONDAY == 4)
	{
		return "FRIDAY";
	}
	if (MONDAY == 5)
	{
		return "SATURDAY";
	}
	if (MONDAY == 6)
	{
		return "SUNDAY";
	}
	else
	{
		return "NOTHING";
	}

}
int quantity(days* array, int size, days MONDAY)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] == MONDAY)
		{
			sum++;
		}
	}
	return sum;
}
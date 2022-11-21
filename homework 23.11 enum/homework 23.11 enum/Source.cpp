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
	int size;
	cout << "Enter size:" << endl;
	cin >> size;
	string* array_days = new string[size];
	days* day_of_week = new days[size];
	days already_printed[7];
	int already_printed_index = 0;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter " << i + 1 << ": " << endl;
		cin >> array_days[i];
		day_of_week[i] = from_string(array_days[i]);

	}
	sort(day_of_week, day_of_week + size); //sorting
	cout << "Sorted list:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout<<from_days(day_of_week[i])<<endl;
	}
	for (int i = 0; i < size; i++)
	{
		int sum=quantity(day_of_week, size, day_of_week[i]);
		string output = from_days(day_of_week[i]);  
		bool is_in_array = false;
		for (int k = 0; k < already_printed_index; k++) //missing printing those times, when a day repeats
		{
			if (day_of_week[i] == already_printed[k])
			{
				is_in_array = true;
				break;
			}
		}
		if (is_in_array == false)
		{
			cout << output << "-->" << sum << "times" << endl;
			already_printed[already_printed_index] = day_of_week[i];
			already_printed_index++;
		}
	}
	return 0;
}
days from_string(string input)   //importing string to days type
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
string from_days(days MONDAY)    //importing days type to string
{
	if (MONDAY == 0)
	{
		return "monday";
	}
	if (MONDAY == 1)
	{
		return "tuesday";
	}
	if (MONDAY == 2)
	{
		return 	"wednesday";
	}
	if (MONDAY == 3)
	{
		return 	"thursday";
	}
	if (MONDAY == 4)
	{
		return "friday";
	}
	if (MONDAY == 5)
	{
		return "saturday";
	}
	if (MONDAY == 6)
	{
		return "sunday";
	}
	else
	{
		return "nothing";
	}

}
int quantity(days* array, int size, days MONDAY)   //counting repeatings
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

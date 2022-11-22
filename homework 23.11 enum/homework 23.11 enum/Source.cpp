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
struct Date
{
	int day;
	days day_of_the_week;
	int mounth;
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
			cout << "Enter " << i + 1 << " day of week: " << endl;
			cin >> array_days[i];
			day_of_week[i] = from_string(array_days[i]);  //from string to days
			if (day_of_week[i] == NOTHING) //in case it's a wrong input
			{
				i--;
			}
			/*while (day_of_week[i] == NOTHING)    //also a soution, but longer one
			{
				cout << "Enter " << i + 1 << " day of week: " << endl;
				cin >> array_days[i];
				day_of_week[i] = from_string(array_days[i]);
			}*/
		}
	
	
	sort(day_of_week, day_of_week + size); //sorting
	cout << endl;
	cout << "Sorted list:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout<<from_days(day_of_week[i])<<endl;
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		int sum=quantity(day_of_week, size, day_of_week[i]);  //counting how many times a day repeats
		string output = from_days(day_of_week[i]);  //from days to string
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
	cout << endl;
	Date array_date[5];   //array that holds our dates            
	for (int h = 0; h < 5; h++) //filling up that array
	{
		cout << "Enter day " << h + 1 << ":" << endl;
		cin >> array_date[h].day;
		while (array_date[h].day < 1 || array_date[h].day>31)
		{
			cout << "Error" << endl;
			cout << "Enter day " << h + 1 << ":" << endl;
			cin >> array_date[h].day;
		}
		cout << "Enter day of week " << h + 1 << ":" << endl;
		string almost_day_of_the_week;
		cin >> almost_day_of_the_week;
		array_date[h].day_of_the_week = from_string(almost_day_of_the_week);
		cout << "Enter mouth " << h + 1 << ":" << endl;
		cin >> array_date[h].mounth;
		while (array_date[h].mounth < 1 || array_date[h].mounth>12)
		{
			cout << "Error" << endl;
			cout << "Enter mouth " << h + 1 << ":" << endl;
			cin >> array_date[h].mounth;
		}
	}
	cout << "Dates that include monday:" << endl;
	for (int h = 0; h < 5; h++) //printing those dates, which include monday
	{
		if (array_date[h].day_of_the_week == MONDAY)
		{
			cout << array_date[h].day << "/";
			cout << from_days(array_date[h].day_of_the_week) << "/";
			cout << array_date[h].mounth;
			cout << endl;
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

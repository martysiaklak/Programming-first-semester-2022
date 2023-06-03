#include <iostream>
#include <list>
#include <fstream>
#include <vector>
using namespace std;

struct date
{
	int month;
	int day;
	int year;
	friend istream& operator>>(istream& is, date& date_)
	{
		is >> date_.month >> date_.day >> date_.year;
		return is;
	}
	friend ostream& operator<<(ostream& os, date& date_)
	{
		os << "mounth: " << date_.month << "day: " << date_.day << "year: " << date_.year << endl;
		return os;
	}
};
class Action
{
private:
	string name;
	int duration;
public:
	friend istream& operator>>(istream& is, Action& action)
	{
		is >> action.name >> action.duration;
		return is;
	}
	friend ostream& operator<<(ostream& os, Action& action)
	{
		os << "action: " << action.name << "duration: " << action.duration << endl;
		return os;
	}

};

class Day_Schedule
{
private:
	list <Action> list;
	date currentdate;
	int quantity;
public:
	/*
	date GetDate()
	{
		return currentdate;
	}*/
	friend istream& operator>>(istream& is, Day_Schedule& day_Schedule)
	{
		is >> day_Schedule.currentdate;
		is >> day_Schedule.quantity;
		for (int i = 0; i < day_Schedule.quantity; i++)
		{
			Action action;
			is >> action;
			day_Schedule.list.push_back(action);
		}
		return is;
	}
	friend ostream& operator<<(ostream& os, Day_Schedule& day_Schedule)
	{
		os << "date: " << day_Schedule.currentdate;
		os << "quantity of actions: " << day_Schedule.quantity<<endl;
		/*for (const Action& action : day_Schedule.list)
		{
			os << action;
		}*/
		/*for (auto i : day_Schedule.list)
		{
			os << day_Schedule.list.front();
			day_Schedule.list.pop_front();
		}*/
		for (const Action& action : day_Schedule.list)
		{
			os << day_Schedule.list.front();
		}
		return os;
	}
};

class Week_Schedule
{
private:
	string name;
	Day_Schedule array[7];
public:
	string getName()
	{
		return name;
	}
	friend istream& operator>>(istream& is, Week_Schedule& week_Schedule)
	{
		is >> week_Schedule.name;
		for (int i = 0; i < 7; i++)
		{
			is >> week_Schedule.array[i];
		}
		return is;
	}
	friend ostream& operator<<(ostream& os, Week_Schedule& week_Schedule)
	{
		os << "your name: " << week_Schedule.name << endl;
		for (int i = 0; i < 7; i++)
		{
			os << week_Schedule.array[i];
		}
		return os;
	}

};
int main()
{
	vector <Week_Schedule> players;
	ifstream file("data.txt");
	while (!file.eof())
	{
		for (int i = 0; i < 2; i++)
		{
			Week_Schedule w;
			file >> w;
			players.push_back(w);
		}
	}
	file.close();
	for (int i = 0; i < 2; i++)
	{
		cout << players[i];
	}
	return 0;
}
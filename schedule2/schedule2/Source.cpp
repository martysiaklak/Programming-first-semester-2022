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
		os << "month: " << date_.month << " day: " << date_.day << " year: " << date_.year << endl;
		return os;
	}
};
class Action
{
private:
	string name;
	int duration;
public:
	int GetTime()
	{
		return duration;
	}
	
	bool operator==(const string& str) const
	{
		return name == str;
	}
	friend istream& operator>>(istream& is, Action& action)
	{
		is >> action.name >> action.duration;
		return is;
	}
	friend ostream& operator<<(ostream& os, Action& action)
	{
		os << "action: " << action.name << endl;
		os<<"duration: " << action.duration << endl;
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
	int GetQ()
	{
		return quantity;
	}
	bool FindWalk()
	{
		for (auto& action : list)
		{
			if (action == "walking")
			{
				return true;
			}
			else
				return false;
		}
	}
	int FindTime()
	{
		for (auto& action : list)
		{
			if (action == "walking")
			{
				return action.GetTime();
			}
		}
	}
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
		os << "date:" << endl;
		os<<day_Schedule.currentdate << endl;
		os << "quantity of actions:" << day_Schedule.quantity << endl;
		for (auto& action : day_Schedule.list)
		{
			os << action << endl;
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
	Day_Schedule* GetArray()
	{
		return array;
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
	try
	{
		vector <Week_Schedule> players;
		ifstream file("players.txt");
		if (!file.is_open())
		{
			throw runtime_error("file is not opened");
		}
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
			cout << players[i].getName()<<endl;
			int max=players[i].GetArray()[0].GetQ();
			int max_q_index;
			for (int j = 0; j < 7; j++)
			{
				if (max < players[i].GetArray()[j].GetQ())
				{
					max = players[i].GetArray()[j].GetQ();
					max_q_index = j;
				}
			}
			cout << "day with max q of actions:" << endl;
			cout << players[i].GetArray()[max_q_index];
			cout << "--------------------------" << endl;
		}
		for (int i = 0; i < 2; i++)
		{
			int time=0;
			cout << players[i].getName()<<endl;
			for (int j = 0; j < 7; j++)
			{
				if (players[i].GetArray()[j].FindWalk() == true)
				{
					time += players[i].GetArray()[j].FindTime();  
				}
			}
			cout << "Time spent on walking: " << time<<endl;
			cout << "--------------------------" << endl;
		}
	}
		catch (runtime_error e)
	{
		cerr << "Error:" << e.what() << endl;
	}
	return 0;
}

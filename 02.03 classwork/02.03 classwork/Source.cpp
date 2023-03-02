#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class Person
{
protected:
	string name;
	int age;
public:
	virtual void input(istream& is) { is >> age >> name; }
	friend istream& operator>>(istream& is, Person& person)
	{
		person.input(is);
		return is;
	}
	virtual void output(ostream& os) { os << age << name; }
	friend ostream& operator<<(ostream& os, Person& person)
	{
		person.output(os);
		return os;
	}
	virtual int get_income() = 0;
};
class Student : public Person
{
private:
	string group;
	int wage;
public:
	virtual void input(istream& is) 
	{ 
		Person::input(is);
		is >> group >> wage;
	}
	friend istream& operator>>(istream& is, Student& student)
	{
		student.input(is);
		return is;
	}
	virtual void output(ostream& os)
	{
		Person::output(os);
		os << group << wage; 
	}
	friend ostream& operator<<(ostream& os, Student& student)
	{
		student.output(os);
		return os;
	}
	int get_income()
	{
		return wage;
	}
	bool operator<(const Student& student)
	{
		return name<student.name;
	}
};
class Worker : public Person
{
private:
	string profession;
	int salary;
public:
	virtual void input(istream& is)
	{
		Person::input(is);
		is >> profession >> salary;
	}
	friend istream& operator>>(istream& is, Worker& worker)
	{
		worker.input(is);
		return is;
	}
	virtual void output(ostream& os)
	{
		Person::output(os);
		os << profession << salary;
	}
	friend ostream& operator<<(ostream& os, Worker& worker)
	{
		worker.output(os);
		return os;
	}
	int get_income()
	{
		return salary;
	}
};
int main()
{
	vector <Person*> list;
	ifstream file("data1.txt");
	file.close();
	while (!file.eof())
	{
		int num;
		Person* temp=0;
		file >> num;
		if (num == 1) { temp = new Student(); }
		if (num == 2) { temp = new Worker(); }
		temp->input(file);
		list.push_back(temp);
	}
	for (int i = 0; i < list.size(); i++)
	{
		list[i]->output(cout);
	}

	/*Worker* worker1 = new Worker();
	Student* student1 = new Student();*/

	

	/*int sum = 0;
	for (int i = 0; i < list.size(); i++)
	{
		sum = sum + list[i].get_income();
	}*/
	int total_income = 0;
	for (int i = 0; i < list.size(); i++)
	{
		total_income=list[i]->get_income();
	}
	cout << "Total income: " << total_income << endl;
	sort(list.begin(), list.end());
	for (int i = 0; i < list.size(); i++)
	{
		list[i]->output(cout);
	}

	return 0;
}
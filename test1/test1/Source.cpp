#include <iostream>
using namespace std;
class Student
{
private:
	string name;
public:
	Student(): name("Victor"){}
	string GetName()
	{
		return name;
	}
	void SetName(string new_name)
	{
		name = new_name;
	}
	friend istream& operator>>(istream& is, Student& student_)
	{
		cout << "Enter name: " << endl;
		is >> student_.name;
		return is;
	}
	friend ostream& operator<<(ostream& os, Student& student_)
	{
		os << "Student name: " << student_.name << endl;
		return os;
	}
};
class Group
{
private:
	Student* students;
	int q;
	string group_name;
	int year;
public:
	Group() { students = nullptr; q = 0; group_name = ""; year = 0; }
	Group(const Group& group) : q(group.q), group_name(group.group_name), year(group.year) 
	{
		students = new Student[q];
		for (int i = 0; i < q; i++) {
			students[i] = group.students[i];
		}
	}
	Group(int q_, string group_name_, int year_) : q(q_), group_name(group_name_), year(year_)
	{
		students = new Student[q_];
	}
	~Group() //деструктор
	{
		delete[] students;
	}
	string GetGroupName()
	{
		return group_name;
	}
	int GetQuantity()
	{
		return q;
	}
	int GetYear()
	{
		return year;
	}
	void SetQuantity(int new_q)
	{
		q = new_q;
	}
	void SetName(string new_name)
	{
		group_name = new_name;
	}
	void SetYear(int new_year)
	{
		year = new_year;
	}
	void SetStudents(Student* new_students) 
	{ 
		students = new_students; 
	}
	bool operator<(const Group& group)
	{
		return  group_name < group.group_name; 
	}
	bool operator>(const Group& group)
	{
		return  year > group.year;
	}
	Group & operator=(const Group& group)
	{
		q = group.q;
		group_name = group.group_name;
		year = group.year;
		students = new Student[q];
		for (int i = 0; i < q; i++) 
		{
			students[i] = group.students[i];
		}
		return *this;
	}
	Student& operator[](int index) //індексування
	{
		return students[index];
	}
	friend istream& operator>>(istream& is, Group& group) {
		cout << "Enter group name:" << endl;
		is >> group.group_name;
		cout << "Enter group year:" << endl;
		is >> group.year;
        cout << "Enter quantity of students:"<<endl;
		is >> group.q;
		cout << "Now add data about students" << endl;
	    group.students = new Student[group.q];
		for (int i = 0; i < group.q; i++) 
		{
			is>> group.students[i];
		}
		return is;
	}
	friend ostream& operator<<(ostream& os, Group& group) {
		os << "Group name:"<<group.group_name<<endl;
		os << "Group year:" << group.year<<endl;
		os << "Quantity of students:" << group.q<< endl;
		
		for (int i = 0; i < group.q; i++)
		{
			os << group.students[i];
		}
		return os;
	}
};
int main()
{
	Group group1, group2, group3;
	cout << "Enter data about group 1" << endl;
	cin >> group1;
	cout << "Enter data about group 2" << endl;
	cin >> group2;
	if (group1 < group2)
	{
		cout << group1;
		cout << group2;
	}
	else 
	{
		cout << group2;
		cout << group1;
	}
	cout << "Group whose year is bigger" << endl;
	if (group1 > group2)
	{
		cout << group1;
	}
	if(group2 > group1)
	{
		cout << group2;
	}
	if (group1.GetQuantity() > group2.GetQuantity())
	{
		group3 = group2;
		cout << group3 << endl;
	}
	else
	{
		group3 = group1;
		cout << group3 << endl;
	}
}
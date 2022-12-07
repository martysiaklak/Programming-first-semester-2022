#include <iostream>
using namespace std;
class Student
{
private:
	string full_name;
	int group_number;
	bool funding;
public:
	Student(): full_name("Marta Klakovych"), group_number(11), funding(true){}
	Student(const Student& student) : full_name(student.full_name), group_number(student.group_number), funding(student.funding) {}
	Student(string full_name1, int group_number1, bool funding1): full_name(full_name1), group_number(group_number1), funding(funding1){}
	friend istream& operator>>(istream& is, Student& student)
	{
		cout << "Enter your full name:" << endl;
		is >> student.full_name;
		cout << "Enter your group number:" << endl;
		is >> student.group_number;
		cout << "Do you get funding?(1/0)" << endl;
		is >> student.funding;
		cout << "----------------------" << endl;
		return is;
	}
	friend ostream& operator<<(ostream& os, Student& student)
	{
		os << "Full name: " << student.full_name << endl; 
		os<<"Group number: "<< student.group_number << endl;
		os << "Funding: " << student.funding << endl;
		os << "--------------------------" << endl;
		return os;
	}
	string get_name()
	{
		return full_name;
	}
	bool get_funding()
	{
		return funding;
	}
	int get_number_of_group() const
	{
		return group_number;
	}
	bool operator<(const Student& student2)
	{
		return get_number_of_group() < student2.get_number_of_group();
	}
	int set_number_of_group()
	{
		group_number = group_number + 1;
		return group_number;
	}
};
void sort(Student* array); //це єдине не працює, не встигла
int main()
{
	Student array[10];
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter data about student " << i + 1 << endl;
		cin >> array[i];
	}
	//Student student;
	sort(array);
	cout << "Sorted group numbers:" << endl;
	for (int i = 0; i < 10; i++)
	{
		//cout << array[i] << endl;
		cout << array[i].get_number_of_group() << endl;
	}
	cout << "Students that get fundation:" << endl;
	for (int i = 0; i < 10; i++)
	{
		if (array[i].get_funding() == true)
		{
			cout << array[i] << endl;
		}
	}
	cout << "New group numbers:" << endl;
	for (int i = 0; i < 10; i++)
	{
		array[i].set_number_of_group();
		cout << array[i].get_number_of_group() << endl;
	}
	return 0;
}
void sort(Student* array)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (array[i] < array[j])
			{
				Student temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}
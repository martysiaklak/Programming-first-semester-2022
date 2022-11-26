#include<iostream>
#include <algorithm>
using namespace std;
class Student
{
private:
	string name;
	int number_of_group;
	int id;
public:
	Student() : name(""), number_of_group(1), id(9) {}
	Student(string name_konstrct, int number_of_group_konstrct, int id_konstrct):name(name_konstrct), number_of_group(number_of_group_konstrct), id(id_konstrct) {}
	string get_name()
	{
		return name;
	}
	int get_number_of_group()
	{
		return number_of_group;
	}
	int get_id()
	{
		return id;
	}
	void set_id(int new_id)
	{
		id = new_id;
	}
	void input()
	{
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter a number of group: ";
		cin >> number_of_group;
		cout << "Enter id: ";
		cin >> id;
	}
	void print()
	{
		cout << name<<" ";
		cout << number_of_group<<" ";
		cout << id<<" ";
		cout << endl;
	}
};
void sort(Student* array, int size);
int main()
{
	int size;
	cout << "Enter size:" << endl;
	cin >> size;
	Student* array_of_students = new Student[size];
	for (int i = 0; i < size; i++)
	{
		array_of_students[i].input();
	}
	int group;
	cout << "Enter a number of group: ";
	cin >> group;
	cout << "students from group " << group << " :" << endl;
	for (int i = 0; i < size; i++)
	{
		if (array_of_students[i].get_number_of_group() == group)
		{
			array_of_students[i].print();
		}
	}
	string name_of_student;
	cout << "Enter a name: ";
	cin >> name_of_student;
	cout << "students with name " << name_of_student<<" :" << endl;
	for (int i = 0; i < size; i++)
	{
		if (array_of_students[i].get_name() == name_of_student)
		{
			array_of_students[i].print();
		}
	}
	cout << "id changed:" << endl;
	for (int i = 0; i < size; i++)
	{
		if (array_of_students[i].get_name() == name_of_student)
		{
			array_of_students[i].set_id(1470);
			array_of_students[i].print();
		}
	}
	sort(array_of_students, size);
}
void sort(Student* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (array[i].get_id() > array[j].get_id())
			{
				Student temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			/*else
			{
				Student temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}*/
		}
	}
	for (int i = 0; i < size; i++)
	{
		array[i].print();
	}
}


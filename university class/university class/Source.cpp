#include <iostream>
using namespace std;

class Student
{
private:
	string StudentName;
	int Id;
	int Specialization;
public:
	//Student() : StudentName(""), Id(0), Specialization(0) {}
	//Student(int id=12) : StudentName(""), Id(id), Specialization(0) {}
	/*Student(int id) :StudentName("lolita"), Id(id), Specialization(2) {}*/
	void SetId(int new_id)
	{
		Id = new_id;
	}
	bool operator==(const Student& student2)
	{
		return Id == student2.Id;
	}
	int GetSpecialization()
	{
		return Specialization;
	}
	friend istream& operator>>(istream& is, Student& student)
	{
		cout << "Enter name: ";
		is >> student.StudentName;
		cout << "Enter id: ";
		is >> student.Id;
		cout << "Enter specialization: ";
		is >> student.Specialization;
		return is;
	}
	friend ostream& operator<<(ostream& os, Student& student)
	{
		os << student.StudentName << ", id: " << student.Id << ", Specialization: " << student.Specialization;
		return os;
	}
};
class Course
{
private:
	string CourseName;
	int Number;
	int CourseSpecialization;
public:
	void SetNumber(int new_number)
	{
		Number = new_number;
	}
	bool operator==(const Course& course2)
	{
		return Number == course2.Number;
	}
	int GetCourseSpecialization()
	{
		return CourseSpecialization;
	}
	friend istream& operator>>(istream& is, Course& course)
	{
		cout << "Enter name: ";
		is >> course.CourseName;
		cout << "Enter number: ";
		is >> course.Number;
		cout << "Enter specialization: ";
		is >> course.CourseSpecialization;
		return is;
	}
	friend ostream& operator<<(ostream& os, Course course)
	{
		os << course.CourseName << ", number: " << course.Number << ", specialization: " << course.CourseSpecialization;
		return os;
	}
};
class Uni
{
private:
	string Adress;
	string UniName;
	int cur;
	int index;
	Course* courses;
	Student* students;
public:
	Uni() {
		courses = new Course[100]; students = new Student[100];
	}
	int StudentsQuantity()
	{
			return cur;
	}
	int CoursesQuantity()
	{
		return index;
	}
	void AddStudent(Student& student)
	{
		students[cur] = student;
		cur++;
	}
	void AddCourse(Course& course)
	{
		courses[index] = course;
		index++;
	}
	void RemoveCourse(Course& course)
	{
		int i;
		for (i = 0; i < index; i++)
		{
			if (courses[i] == course)
			{
				for (int j = i; j < index-1; j++)
				{
					courses[j] = courses[j + 1];
				}
				index--;
				break;
			}
		}
	}
	void RemoveStudent(Student& student)
	{
		int i;
		for (i = 0; i < cur; i++)
		{
			if (students[i] == student)
			{
				for (int j = i; j < cur - 1; j++)
				{
					students[j] = students[j + 1];
				}
				cur--; 
				break; 
			}
		}
	}


	//void RemoveStudent(Student& student)
	//{
	//	int i = 0;
	//	for (int i = 0; i < cur; i++)
	//	{
	//		if (students[i] == student)
	//		{
	//			for (int j = i; j < cur; j++)
	//			{
	//				students[j] = students[j + 1];
	//			}
	//		}
	//	}
	//}
	void StudentsForCourse(Course& course)
	{
		int students_quantity = 0;
		cout << "Students that have to attend this course:";
		for (int i = 0; i < cur; i++)
		{
			if (course.GetCourseSpecialization() == students[i].GetSpecialization())
			{
				cout << students[i] << endl;
				students_quantity++;
			}
		}
		if (students_quantity == 0)
		{
			cout << "There are no students that have to attend this course" << endl;
		}
	}
	void CoursesForStudent(Student& student)
	{
		int courses_quantity=0;
		cout << "Courses avalible for this student:";
		for (int i = 0; i < index; i++)
		{
			if (student.GetSpecialization() == courses[i].GetCourseSpecialization())
			{
				cout << courses[i] << endl;
				courses_quantity++;
			}
		}
		if (courses_quantity == 0)
		{
			cout << "There are no courses available." << endl;
		}
	}
	void PrintStudents()
	{
		cout << "all of the students:" << endl;
		for (int i = 0; i < cur; i++)
		{
			cout << students[i] << endl;
		}
	}
	void PrintCourses()
	{
		cout << "all of the courses:" << endl;
		for (int i = 0; i < index; i++)
		{
			cout << courses[i] << endl;
		}
	}
	friend istream& operator>>(istream& is, Uni& university)
	{
		cout << "Enter name: ";
		is >> university.UniName;
		cout << "Enter adress: ";
		is >> university.Adress;
		return is;
	}

};
int main()
{
	Uni university;
	cout << "Hello, enter data about your university" << endl;
	cin >> university;
	int answer;
	do
	{
		cout << "1. Add a student" << endl;
		cout << "2. Remove a student" << endl;
		cout << "3. Add a course" << endl;
		cout << "4. Remove a course" << endl;
		cout << "5. Courses avalible for a particular student" << endl;
		cout << "6. Students that have to attend a particular course" << endl;
		cout << "7. Exit" << endl;
		cout << "-------------------------------------------------------" << endl;
		cin >> answer;
	Student student;
	Course course;
	switch (answer) {
	case 1:
		cin >> student;
		university.AddStudent(student);
		university.PrintStudents();
		break;
	case 2:
		if (university.StudentsQuantity() == 0)
		{
			cout << "There are 0 students" << endl;
			break;
		}
		else
		{
			cout << "Enter student's id:" << endl;
			int id;
			cin >> id;
			student.SetId(id);
			university.RemoveStudent(student);
			university.PrintStudents();
		}
		break;
	case 3:
		cin >> course;
		university.AddCourse(course);
		university.PrintCourses();
		break;
	case 4:
		if (university.CoursesQuantity() == 0)
		{
			cout << "There are 0 courses" << endl;
			break;
		}
		else
		{
			cout << "Enter the number of the course:" << endl;
			int n;
			cin >> n;
			course.SetNumber(n);
			university.RemoveCourse(course);
			university.PrintCourses();
		}
		break;
	case 5:
		cout << "Enter student's id:" << endl;
		int id;
		cin >> id;
		student.SetId(id);
		university.CoursesForStudent(student);
		break;
	case 6:
		cout << "Enter the number of the course:" << endl;
		int n;
		cin >> n;
		course.SetNumber(n);
		university.StudentsForCourse(course);
		break;
	default:
		break;
	}
	} while (answer != 7);
	return 0;
}
#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
T sort(T* array, int size)
{
  int i, j;
  for (i = 0; i < size - 1; i++)
  {
       for (j = 0; j < size - i - 1; j++)
       {
          if (array[j] > array[j + 1])
          {
              swap(array[j], array[j + 1]);
          }
       }
  }
  return *array;
}
class Person
{
private:
    string name;
    string address;
public:
    Person(string name_, string address_) : name(name_), address(address_) {}
    string getname() const
    {
        return name;
    }
    bool operator>(const Person& person1)
    {
        return name > person1.getname();
    }
    friend ostream& operator<<(ostream& os, Person& p)
    {
        os << "name:" << p.name << endl;
        os << "address:" << p.address << endl;
        return os;
    }
};
int main()
{
    int int_arr[] = { 5, 2, 9, 1, 5 };
    sort(int_arr, 5);
    cout << "sorted int array:" << endl;
    for (int i = 0; i < 5; i++) 
    {
        cout <<i<<": "<< int_arr[i] << endl;
    }
   
    string string_arr[] = { "apple", "dog", "cat", "banana" };
    sort(string_arr, 4);
    cout << "sorted string array:" << endl;
    for (int i = 0; i < 4; i++) 
    {
        cout << i << ": "<< string_arr[i] << endl;
    }

    Person person_arr[]={Person("Bob", "456 Oak Ave."),Person("Charlie", "789 Elm St."), Person("Alice", "123 Main St.")};
    sort(person_arr, 3);
    cout << "sorted person array:" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i << ": " << person_arr[i] << endl;
    }

	return 0;
}
#include <iostream>
using namespace std;
enum dogbreed
{
	HASKI,
	BULDOG,
	TAKSA,
	CHIHUAHUA,
	NOBREED

};
void add_el(dogbreed * array, int size); 
dogbreed str_to_dogbreed(string name);
int main()
{
	cout << "Enter size:" << endl;
	int size;
	cin >> size; 
	dogbreed* array_breed = new dogbreed[size];
	add_el(array_breed, size);
	bool finish = false;
	while (finish == false)
	{
		string input;
		cout << "Enter a breed: " << endl;
		cin >> input;
		dogbreed result = str_to_dogbreed(input);
		for (int i = 0; i < size; i++)
		{
			if (result == array_breed[i])
			{
				cout << "Breed found" << endl;
				finish = true;
				break;
			}
		}
		if (finish==false)
		{
			cout << "Breead isn't found" << endl;
		}
	}
	return 0;
}
void add_el(dogbreed* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = dogbreed(rand() % 4);
		switch(array[i])
			{
		case 0:
		{
			cout << "breed-->" << "HASKI" << endl;            
		}
		break;
		case 1:
		{
			cout << "breed-->" << "BULDOG" << endl;
		}
		break;
		case 2:
		{
			cout << "breed-->" << "TAKSA" << endl;
		}
		break;
		case 3:
		{
			cout << "breed-->" << "CHIHUAHUA" << endl;
		}
		break;

			}
	}
}
dogbreed str_to_dogbreed(string name)
{
	for (int i = 0; i < name.size(); ++i) {
		name[i] = tolower(name[i]);
	}
	if (name == "haski")
	{
		return HASKI;
	}
	else if (name == "buldog")
	{
		return BULDOG;
	}
	else if (name == "taksa")
	{
		return TAKSA;
	}
	else if (name == "chihuahua")
	{
		return CHIHUAHUA;
	}
	else
	{
		return NOBREED;
	}

}

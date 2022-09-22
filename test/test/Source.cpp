#include <iostream>
#include<string>
#include<math.h>
using namespace std;
int main()
{
	/*cout << "Hello world" << endl;
	cout << "7+3="<<7+3<<endl;
	cout << "787.89" << endl;
	cout << 'h' << endl;
	return 0; */
	/*int number;
	cout << "enter your favorite number" << endl;
	cin >> number;
	cout << "Number=" << number<< endl;
	number = number + 1;
	cout << "Number=" << number;
	return 0;*/
	//ввести сторону квадрата і вивести його площу і периметр
	float side;
	cout << "enter a side" << endl;
	cin >> side;
	float S;
	S = side * side;
	cout << "S=" << S << endl;
	cout << "P=" << 4 * side << endl;
}
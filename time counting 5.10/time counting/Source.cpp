#include <iostream>
#include <math.h>
using namespace std;
int seconds, minutes, hours;
int main()
{
    cout << "Enter a number of seconds:";
    cin >> seconds;
    minutes = seconds / 60;
    hours = minutes / 60;
    cout << "A number of minutes:" << minutes << endl;
    cout << "A number of hours:" << hours << endl;

}

#include <iostream>
#include <math.h>
using namespace std;
bool is_even(double n);
int main()
{
    cout << is_even(0.5);
    cout << is_even(0);
    cout << is_even(1);
    cout << is_even(2);
    cout << is_even(-4);
    cout << is_even(-0.5);
    return 0;
}
bool is_even(double n)
{
    double k = abs(n);

    if (k - static_cast<int>(k) == 0 && static_cast<int>(k) % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    // your code here
}
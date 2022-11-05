#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d, lcm;
    cout << "Enter the first number" << endl;
    cin >> a;
    cout << "Enter the second number" << endl;
    cin >> b;
    cout << "Enter the third number" << endl;
    cin >> c;
    cout << "Enter the fourth number" << endl;
    cin >> d;

    int max(int x, int y);


    int left_max = max(a, b);
    int right_max = max(c, d);
    int final_max = max(left_max, right_max);

   
    lcm = final_max;
    while (1)
    {
        if (lcm % a == 0 && lcm % b == 0 && lcm % c == 0 && lcm % d == 0)
        {
            cout << "lcm is: " << lcm;
            break;
        }
        lcm++;
    }

    return 0;
}
int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }

}
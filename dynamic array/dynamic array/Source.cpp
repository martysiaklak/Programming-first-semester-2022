#include <iostream>
using namespace std;

int main()
{
    int size;
    cin >> size;
    float* array = new float[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i + 1 << "number:";
        cin >> array[i];
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "  ";
    }
    delete[]array;
    return 0;
}
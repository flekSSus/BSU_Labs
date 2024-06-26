#include <iostream>
using namespace std;

int main()      //Факториал
{
    unsigned long long int f=1;
    int value;
    cout<< "Enter value to get its factorial: ";
    cin>> value;
    while(value<0)
    {
        cout << "\nExeption! There is no solution!\n";
        cin >> value;
    }
    if (value == 0)
    {
        cout<< value << "! = " << f;
        return 1;
    }
    for (int i = value;i > 0;i--)
    {
        f = f * i;
    }
    cout<< value << "! = " << f;
    return 1;
}



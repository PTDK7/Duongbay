#include<iostream>
#include <math.h>
using namespace std;

int main()
{
    int u = 0, i = 0, a;
    cout << "Nhap a: ";
    cin >> a;
    if (a>0) 
    {
        i = a%10;
        cout << i << endl;
        a /= 10;
    }
    for (; a>0; )
    {
        u = a % 10;
        a /= 10;
    }
    cout << u;
    return 0;
}
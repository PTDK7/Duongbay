#include<iostream>
#include <math.h>
using namespace std;

int main()
{
    int u = 0, tongchuso = 0, a;
    cout << "Nhap a: ";
    cin >> a;
    for (; a>0; )
    {
        u = a % 10;
        a /= 10;
        tongchuso += u;
    }
    cout << tongchuso;
    return 0;
}
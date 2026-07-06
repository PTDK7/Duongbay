#include <iostream>
#include <math.h>
using namespace std;

int main ()
{
    int n, k, a = 0, b = 1;
    cout << "Nhap n: ";
    cin >> n;
    cout << a << " " << b;
    for (int i = 2; i<=(n-1) ; i++ )
    {
        k = a + b;
        cout << " " << k << " ";
        if (i % 2 == 0) a = k;
        else b = k;
    }

}
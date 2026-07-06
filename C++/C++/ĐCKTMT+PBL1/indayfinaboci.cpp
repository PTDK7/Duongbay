#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a=0, n, u, a0=0, a1=1;
    cout << "Nhap so phan tu can tinh:";
    cin >> n;
    cout << a0 << endl << a1 << endl;
    u = (n-2);
    for (int i = 1; i<=u; i++)
    {
        a = (a0 + a1);
        cout << a << endl;
        if (i % 2 != 0) a0 = a;
        else a1 = a;
    }
    return 0; 
}
#include <iostream>
using namespace std;

int main ()
{
    /*int i,n ;
    cout << "Nhập số n = " ;
    cin >> n;
    for (i=1; i <= 10; i++)
    {cout << n << "*" << i << "=" << n*i << endl;}
    return 0;*/
    int i=1,n ;
    cout << "Nhập số n = " ;
    cin >> n;
    while (i <= 10)
    {cout << n << "*" << i << "=" << n*i << endl;
    i++; }
    return 0;
}
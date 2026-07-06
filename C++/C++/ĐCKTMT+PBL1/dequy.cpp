#include<iostream>
#include<math.h>
using namespace std;

int sochuso(long long a)
{    if (a<10)
        return 1;
    else return 1 + sochuso(a/10);
}

int main ()
{
    long long n;
    cout << "Nhap n: ";
    cin >> n;
    sochuso(n);
    cout << sochuso(n);
}
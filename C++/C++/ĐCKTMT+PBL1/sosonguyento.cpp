#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main()
{
    int a, b, n;
    int i=0;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    for (n=a; n<=b; n++) 
    { 
        isPrime(n);
    if (isPrime(n) == true) 
    { cout << n << endl;
        i += 1;
    }
    }
    cout << "So cac so nguyen to trong [" << a << ";" << b << "] la: "<< i;
    return 0;
}
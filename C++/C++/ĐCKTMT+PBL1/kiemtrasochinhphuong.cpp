#include<iostream>
#include<math.h>
using namespace std;

bool isPrime(int n)
{
    int phannguyen;
    phannguyen = sqrt(n);
    if (phannguyen * phannguyen == n) 
    {   cout << n << " la so chinh phuong";
        return true; }
    else 
    {   cout << n << " khong la so chinh phuong";
        return false;}
}

int main()
{
    int n;
    cout << "Nhap so n: ";
    cin >> n;
    isPrime(n);
    return 0;
}
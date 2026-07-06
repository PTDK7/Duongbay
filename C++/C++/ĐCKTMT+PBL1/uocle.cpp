#include <iostream>
#include <math.h>
using namespace std;

int main ()
{
    int n, u=0;
    int k = sqrt(n);
    cout << "Nhap so n: ";
    cin >> n;
    for (int i=1; i<=k; i++)
    {
        if (n%i == 0) 
        { if (i%2 == 1) u +=1; }
        else u=u;
    }
    cout << "So uoc le la: "<< u;
}
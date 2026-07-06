#include <iostream>
#include <math.h>
using namespace std;

int ketquagiaithua;
void giaithua(int n)
{   int u=1;
    for (int i=1; i<=n; i++)
    {
        u *= i;
    }
    ketquagiaithua = u;
}

int main()
{
    int a, i;
    int u = 0;
    cout << "Nhap a: ";
    cin >> a;
    int a_goc = a; 
    for (; a>0 ; )
    {
        i = a % 10 ;
        giaithua(i);
        a /= 10;
        u += ketquagiaithua;
    }
    if (u==a_goc) cout << "YES";
    else cout << "NO";
    return 0;
}

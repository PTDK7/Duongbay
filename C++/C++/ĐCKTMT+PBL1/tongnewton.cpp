#include<iostream>
#include<math.h>
using namespace std;

int S(int x, int y, unsigned short n)
{   int k=n, a=0, u, v, tong=0;
    for (int i=n; i>=0; i--)
    {
        u = pow(x, k);
        v = pow(y, a); 
        tong += (u*v);
        k--;
        a = (n-k);
    }
    return tong;
}

int main ()
{
    int x, y;
    unsigned short n;
    cin >> x >> y >> n;
    S(x, y, n);
    cout << S(x, y, n);
    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

int giaithua(int n)
{
    int K=1;
    for(int i=1; i <= n; i++)
    K = K*i;
    return K;
}

int main ()
{
    int n, S=0;
    cout << "Nhap n: ";
    cin >> n;
    if ( n == 0) cout << "1";
    else {
    for (int u=1; u<=n; u++)
    {
    giaithua(u);
    S = S+ giaithua(u);
    }
    cout << S; }
}
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
    int N;
    int S = 0;
    cout << "Nhap N: ";
    cin >> N;
    if ( N == 0) cout << "1";
    else {
    for ( int i=1; i <= (2*N+1); i = i+2)
    {
        giaithua(i);
        S = S + giaithua(i);
    }
    cout << S;
    return 0; }
}

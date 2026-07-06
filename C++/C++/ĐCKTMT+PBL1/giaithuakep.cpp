#include<iostream>
#include<math.h>
using namespace std;

int SFac(int N)
{   int i, A=1;
    for (i=N; i>0; i-=2) A*= i;
    return A;
}

int main ()
{   int N, C, S;
    cout << "Nhap N:";
    cin >> N;
    cout << "Nhap C:";
    cin >> C;
    SFac(N);
    S = SFac(N) + C;
    cout << "Giai thua kep cua " << N << "la: "<< S;
}
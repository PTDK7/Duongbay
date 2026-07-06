#include<iostream>
#include<math.h>
using namespace std;

int Sum1(int N)
{
    int S=0, u;
    for (int i=0; i<=N; i++)
    {
        u = pow(2, (2*i + 1));
        S += u;
    }
    //cout << S;
    return S;
}
int Sum2(int N)
{
    int a=0, p;
    for (int i=0; i<=N; i++)
    {
        p = pow(2, (2*i));
        a += p;
    }
    //cout << a;
    return a;
}

int main()
{
    int N, S_1=0, S_2=0;
    cin >> N;
        Sum2(N);
        S_2 = Sum2(N);
        Sum1(N);
        S_1 = Sum1(N);
    cout << S_2 << endl;
    cout << S_1;
}
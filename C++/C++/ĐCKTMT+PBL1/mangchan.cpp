#include<iostream>
#include<math.h>
using namespace std;

int main ()
{
    int i, N;
    cin >> N;
    long long array[N];
    for (i=0; i<N; i++) cin >> array[i];
    for (i=0; i<N; i++)
    {
        if (i % 2 == 0) cout << array[i];
    }
    return 0;
}
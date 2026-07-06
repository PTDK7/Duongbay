#include <iostream>
#include <math.h>
using namespace std;

int main ()
{
    int C, N, S_chan=0, S_le=0;
    cout << "Nhap vao so phan tu N:" << endl;
    cin >> N >> C;
    long long array[N];
    for (int a = 0; a < N; a++) cin >> array[a];
    for (int a = 0; a < N; a++)
    {
        if (array[a] % 2 == 0) S_chan += array[a];
        else S_le += array[a];
    }
    cout << (S_chan + C) << endl;
    cout << (S_le + C);
    return 0;
}
#include <iostream>
using namespace std;

int a[100];

int tongle(int u, int *a)
{
    int S = 0;
    for (int K = 0; K < u; K++)
    {
        if (a[K] % 2 != 0) S += a[K];
    }
    return S;
}

int tongchan(int u, int *a)
{
    int S = 0;
    for (int K = 0; K < u; K++)
    {
        if (a[K] % 2 == 0) S += a[K];
    }
    return S;
}

void loaisodau(int a[], int N)
{
    for (int i = 1; i < N; i++)
    cout << a[i] << " ";
}

void loaisocuoi(int a[], int N)
{
    for (int i = 0; i < (N-1); i++)
    cout << a[i] << " ";
}

void solonthuhai (int N, int a[])
{
    int a_max = a[0];
    for (int i = 0; i <  N; i++)
    {
        if (a[i] > a[0])  a_max = a[i];
    }

    for (int i = 0; i <  N; i++)
    {
        if (a[i] == a_max)  a[i]=0;
    }

    for (int i = 0; i < N; i++)
    {
        if (a[i] > a[0])  a_max = a[i];
    }
    cout << a_max << " ";
}

void sonhothuhai (int N, int a[]) 
   {
    int min1 = 2147483648, min2 = 2147483647;

    for (int i = 0; i < N; i++) {
        if (a[i] < min1) {
            min2 = min1;
            min1 = a[i];
        } 
        else if (a[i] < min2 && a[i] > min1) {
            min2 = a[i];
        }
    }
    cout << min2;
   }

int main()
{    int N = 9;

    for (int i = 0; i < N; i++)
    cin >> a[i];

    // for (int i = 0; i < N; i++)
    // cout << *(a + i) << " ";

    // for (int i = 0; i < N; i++)
    // tongle(N, a);
    // cout << tongle(N, a) << " ";

    // for (int i = 0; i < N; i++)
    // tongchan(N, a);
    // cout << tongchan(N, a) << endl;

    // loaisodau (a, N);
    // loaisocuoi (a, N);

    solonthuhai (N, a);
    sonhothuhai (N, a);

}
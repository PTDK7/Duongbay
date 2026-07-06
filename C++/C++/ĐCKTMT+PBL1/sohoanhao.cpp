#include<iostream>
#include<cmath>
using namespace std;

void sohoanhao(int n)
{   int a = 0;
    for (int i=1; i<n; i++)
        if (n % i == 0) a += i;
    if (a == n) cout << n << " la so hoan hao"<< endl;
}
int main()

{
    int a, i;
    cout << "Nhap so a: ";
    cin >> a;
    if (a < 6) cout << "Khong co so hoan hao";
    else 
    {
        for (i=6; i <= a; i++ )
        sohoanhao(i);
    }
    return 0;
}
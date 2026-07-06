#include <iostream>
using namespace std;

int main()
{
    int i, n; 
    long long a_min, a_max ;
    long long a[n]; 
    cout << "Nhap so phan tu cua mang:";
    cin >> n; 
    for (i=1; i<=n; i++) cin >> a[i];
    a_min = a[1];
    a_max = a[1];
    for (i=1; i<=n; i++)
    { 
        if (a_max < a[i]) a_max = a[i];
        else a_max += 0;
    }
    for (i=1; i<=n; i++)
    {
    if (a_min > a[i])  a_min = a[i];
    else a_min += 0; 
    }
    cout << "So be nhat la: "<< a_min << endl;
    cout << "So lon nhat la: "<< a_max << endl;
    return 0;
}
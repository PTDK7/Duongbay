#include<iostream>
#include<cmath>
using namespace std;

void songuyento (int n, int i) 
{
        if (i < 2) return;
        else if (i = 2) cout << i;
        else
        {
            for ( n = 2; n <= sqrt(i); n++)
            {
                if (i % n == 0) return;
                else cout << i;
            }
        }
}
    int main()
{
    int i, n, a[i];
    cin >> n;
    for (i=0; i<n; i++)
    { 
        cout << "Nhập số ở mảng thứ a[" << i << "]"<< endl;
        cin >> a[i];
    }
    for (i=0; i<n; i++)
    {
        songuyento (n, a[i]);
    }
    return 0;
}
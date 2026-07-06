#include <iostream>
using namespace std;
int main()
{
    int u = 1, n, m;
    cout << "Nhập n = ";
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        u *= i;
    }
    cout << u;
    return 0;
}

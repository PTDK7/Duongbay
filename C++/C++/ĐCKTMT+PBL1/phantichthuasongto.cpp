#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a, k = sqrt(a);
    cout << "Nhap so a: ";
    cin >> a;
    for (int k = 1; a > 0; k++)
    {
            if (a % 2 == 0) 
            { cout << "2 ";
                a /= 2;
            }
            else for (int i = 3; i <= k; i += 2) {
            while (a % i == 0) {
            cout << i << " ";
            a /= i;
            if (a == 1) return 0; } }
    }
    return 0;
}

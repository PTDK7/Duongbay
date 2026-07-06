#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Nhập số n =" ;
    cin >> n;
    if ( n % 7 == 0 )
    {cout << "Số đó chia hết cho 7" << endl;}
    else
    {cout << " Số đó không chia hết cho 7" << endl ;}
    return 0;
}
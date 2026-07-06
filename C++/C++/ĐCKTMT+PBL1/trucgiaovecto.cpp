#include<iostream>
using namespace std;

void trucgiao( int x, int y, int z, int k)
{
    if ((x*z + y*k)==0)
    cout << "a va b truc giao";
    else cout << "a va b khong truc giao";
}

int main()
{
    int x, y, z, k;
    do { cout << "Nhap vecto a: ";
    cin >> x >> y;
    cout << "Nhap vecto b: ";
    cin >> z >> k;}
    while ((x == 0 && y == 0)|| (z == 0 && k == 0));
    trucgiao(x, y, z, k);
    return 0;
}

#include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    cout << "Nhap a,b,c :";
    cin >> a >> b >> c;
    if (a == 0 || b == 0 || c == 0 || a<0 || b<0 || c<0) cout << "Khong la tam giac";
    else {
    if (a+b>c && a+c>b && b+c>a)
{   
    if (a==b==c) cout << "Tam giac deu";
    else cout << "Khong la tam giac deu" ;
}
    else cout << "Khong la tam giac" ;
}
    return 0;
}
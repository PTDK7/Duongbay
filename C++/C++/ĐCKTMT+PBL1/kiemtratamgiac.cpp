#include <iostream>
#include <cmath> 
using namespace std;
int main()
{
    double a, b, c;
    cout << "Nhap a,b,c :";
    cin >> a >> b >> c;
    if (a+b>c || a+c>b || b+c>a) { 
             //cout << "Bo ba so la tam giac" << endl;
            if (a==b && b==c)
                { cout << "Tam giac deu";}
            else if ((a*a + b*b == c*c) && (a==b) || (c*c + b*b == a*a) && (c==b) || (a*a + c*c == b*b) && (a==c)) 
                { cout << "Tam giac vuong can";}
            else if (a==b || b==c || c==a ) 
                { cout << "Tam giac can";}
            else if (a*a + b*b == c*c || c*c + b*b == a*a || a*a + c*c == b*b ) 
                { cout << "Tam giac vuong";}
            else 
                { cout << "Chi la tam giac thuong";} 
         }
    else cout << "Bo ba so khong la tam giac" << endl; 
    return 0;
}
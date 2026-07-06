#include <iostream>
#include <cmath> 
using namespace std;
void chuvi (double a, double b, double c)
    {   double C = (a + b + c);
        cout << "Chu vi la:" << C << endl;
    }
void dientichdeu (double a)
    {   double S = (a*a)*sqrt(3)/4;
        cout << "Dien tich tam giac deu la:"<< S;
    }
void dientichvuong (double a, double b, double c)
    {
        if (a*a + b*b == c*c) 
                { double S = 0.5 * a * b;
                    cout << "Dien tich tam giac vuong la:" << S; }
        else if (c*c + b*b == a*a) 
                { double S = 0.5 * c * b;
                    cout << "Dien tich tam giac vuong la:" << S;}
        else 
        { double S = 0.5 * c * a;
                cout << "Dien tich tam giac vuong la:" << S;}
    }
void dientichthuong (double a, double b, double c)
    {   double C = (a + b + c);
        double S = sqrt((0.5 * C)*((0.5 * C)-a)*((0.5 * C)*b)*((0.5 * C)-c));
        cout << "Dien tich tam giac thuong la:" << S ;
    }
int main()
{
    double a, b, c, C, S;
    cout << "Nhap a,b,c :";
    cin >> a >> b >> c;
    if (a == 0 || b == 0 || c == 0 || a<0 || b<0 || c<0) cout << "Khong la tam giac";
    else {
    if (a+b>c && a+c>b && b+c>a) 
        { cout << "Bo ba so la tam giac" << endl;
            if (a==b && b!=c || b==c && c!=a || c==a && a!=b) 
                { cout << "Tam giac can";
                    chuvi(a, b, c);
                    dientichthuong(a, b, c);}
            else if (a==b && b==c && c==a)
                { cout << "Tam giac deu";
                    chuvi(a,b,c);
                    dientichdeu(a);}
            else if (a*a + b*b == c*c || c*c + b*b == a*a || a*a + c*c == b*b ) 
                { cout << "Tam giac vuong";
                    chuvi(a,b,c);
                    dientichvuong(a,b,c);}
            else if ((a*a + b*b == c*c) && (a==b) || (c*c + b*b == a*a) && (c==b) || (a*a + c*c == b*b) && (a==c)) 
                { cout << "Tam giac vuong can";
                    chuvi(a,b,c); 
                    dientichvuong(a,b,c);}
            else 
                { cout << "Chi la tam giac thuong";
                  chuvi(a,b,c);
                  dientichthuong(a,b,c);} 
         }
    else cout << "Bo ba so khong la tam giac" << endl; }
    return 0;

}
#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    int a, b, c;
    double d;
    cout << "Nhập các số a, b, c:"; 
    cin >> a >> b >> c;
    d = b*b - 4*a*c;
    if (d<0) cout << "Phương trình vô nghiệm" << endl;
    else if (d==0) cout << "Phương trình có nghiệm kép: x= -b/2a ="<< -b / (2*a) ;
    else {cout << "phương trình có 2 nghiệm phân biệt" << "x1 = (-b + sqrt(d))/2a = " << (- b + sqrt(d)) / (2*a) << endl;
        cout << "x2 = (-b - sqrt(d))/2a = " << (- b - sqrt(d)) / (2*a)<< endl; }
    return 0;

}
#include <iostream>
using namespace std;

int main ()
{
    double score;
    int n;
    cout << "Số điểm của học sinh đó là: " ;
    cin >> n;
    if (n < 5.0)
    {cout << "Học sinh yếu" << endl;}
    else if ( n <= 6.4)
    {cout << "Học sinh trung bình" << endl;}
    else if ( n <= 7.9)
    {cout << "Học sinh khá" << endl;}
    else if ( n <= 8.9)
    {cout << "Học sinh giỏi" << endl;}
    else 
    {cout << "Học sinh xuất sắc" << endl;}
    return 0;
}

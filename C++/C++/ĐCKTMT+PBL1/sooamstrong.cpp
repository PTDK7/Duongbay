#include <iostream>
#include <math.h>
using namespace std;

int main()
{
int n, u, i=0, a, tongamrstrong=0;
cout << "Nhap n: ";
cin >> n;
int n_goc=n;
int k=n; 
for (; n>0; )
{
    u = n%10;
    n /=10;
    i +=1;
}
for (; k>0; )
{
    a = k%10;
    pow(a, i);
    tongamrstrong += round(pow(a, i));
    k /= 10;
}
cout << tongamrstrong << endl;
if (tongamrstrong == n_goc) cout << "YES";
else cout <<"NO";
return 0;
}

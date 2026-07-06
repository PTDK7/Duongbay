#include <bits/stdc++.h>
using namespace  std;

int main()
{
    long long n,s=2;
    cin >> n;
    while (n>=0){
        if (n%s==0){
            cout << s << " ";
            n=n/s;
        }
        else s+=1;
    }
    return 0;
}

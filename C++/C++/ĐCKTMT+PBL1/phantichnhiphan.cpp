#include <bits/stdc++.h>
using namespace  std;

void  nhiphan(long long n){
    if (n==0) return; 
    nhiphan(n/2);
    cout << n%2;
}
int main()
{
    long long n;
    cin >> n;
    nhiphan(n);
    return 0;
}
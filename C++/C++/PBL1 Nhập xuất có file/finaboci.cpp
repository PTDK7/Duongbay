#include <iostream>
#include <fstream>
using namespace std;

int fibo(int n) {
if (n <= 1) return n;
return fibo(n - 1) + fibo(n - 2);
}

int main(){
    int n, k;
    ifstream fin("InpFibo.txt");
    ofstream fout("OutFibo.txt");
    while (fin >> n)
    { for (int i = 0; i < n; i++){
        fin >> k;
        for (int i = 1; ; i++){
            if (fibo(i) >= k){
                fout << fibo (i) << " " << i << endl;
                break;
            }
        }

    } }
    return 0;
}
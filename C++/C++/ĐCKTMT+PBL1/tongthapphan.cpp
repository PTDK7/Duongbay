#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;    

int main() {
    ifstream fin("fxInp.txt");
    ofstream fout("fxOut.txt");

    int x, n = 0; int a[100];
    while (!fin.eof()) {
        fin >> x;
        a[n] = x;
        n++;
    }

    double s = 0;
    for (int i = 1; i <= n; i++) {
        int u = a[0];
         s += (a[i] + u) / (u * u);
    }
    fout << s << endl;

    fin.close();
    fout.close();
    return 0;
}
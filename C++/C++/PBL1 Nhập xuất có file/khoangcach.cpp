#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main () {
    double a[100], b[100], c[100], e[100];
    int n = 0, k;
    double x1, y1, z1;

    ifstream fin ("InpPoint3D.txt");
    ifstream fin1("InpLength.txt");
    ofstream fout ("OutPoint3D.txt");

    while (fin >> x1 >> y1 >> z1) {
        b[n] = x1;
        c[n] = y1;
        e[n] = z1;
        a[n] = sqrt(pow(b[n], 2) + pow(c[n], 2) + pow(e[n], 2));
        n++;
    }

    while (fin1 >> k) {
        int s = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] <= k) {
                s++;
            }
        }
        fout << s << endl;
    }

    fin.close();
    fin1.close();
    fout.close();
    return 0;
}
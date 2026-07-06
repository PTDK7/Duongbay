#include <iostream>
#include <fstream>
using namespace std;

bool thanghang(int a, int b, int c, int x, int y, int z, int u, int v, int w)
{   double dx1 = x - a;
    double dy1 = y - b;    
    double dz1 = z - c;
    double dx2 = u - a;
    double dy2 = v - b;
    double dz2 = w - c;
    if (dx1 * dy2 - dy1 * dx2 == 0 && dy1 * dz2 - dz1 * dy2 == 0 && dz1 * dx2 - dx1 * dz2 == 0) return true;
    else return false;
}

int main (){
    double x[1000], y[1000], z[1000];
    int n = 0, s = 0;
    ifstream fin ("InpPoints.txt");
    ofstream fout ("OutPoints.txt");
    while (fin >> x[n] >> y[n] >> z[n]) {
        n++;
        for (int i = 0; i < n-2; i++)
            for (int j = i+1; j < n-1; j++)
                for (int k = j+1; k < n; k++)
                {
                    if (thanghang(x[i], y[i], z[i], x[j], y[j], z[j], x[k], y[k], z[k]) == true) s = s + 1;
                    else s = s; }

            }
    fout << s;
    fin. close();
    fout. close();
    return 0;
}
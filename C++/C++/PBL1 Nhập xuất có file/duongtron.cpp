#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main ()
{
    ifstream fin ("InpCir.txt");
    ofstream fout ("OutCir.txt");
    double x, y, N, a, b, m;
    double s = 0, u = 0, v = 0;

    while (fin >> x >> y)
    {
        fin >> N;
        fin >> m; 
        for (int i = 0; i < m ; i++)
        {
            fin >> a >> b;
            double k;
            k = sqrt ((a-x)*(a-x) + (b-y)*(b-y));
            if (k > N) v = v + 1;
            else if (k == N) u = u + 1;
            else s = s + 1;
        }
    }

    fout << s << " " << u << " " << v;
    fin.close();
    fout.close();
    return 0;
}
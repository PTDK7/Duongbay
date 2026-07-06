#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int N, a[N][N], s = 0, u = 0;
    ifstream fin ("Diag.txt");
    ofstream fout ("OutDiag.txt");

    while (fin >> N)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                fin >> a[i][j];
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        s += a[i][i];
    }
    fout << s << " ";

    for (int i = 0; i < N; i++)
    {
        u += a[i][(N - 1) - i];
    }
    fout << u;

    fin.close();
    fout.close();
    return 0;  
}
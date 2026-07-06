#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main (){
    int a[1000][1000];
    int N;

    ifstream fin ("nhapvao.txt");
    ofstream fout ("inra.txt");

    while (fin >> N){
        for (int i = 0; i < (N); i++)
        {
            for (int j = 0; j < N; j++)
            fin >> a[i][j];
        } }

        for (int i = 0; i < (N); i++)
        {
            for (int j = 0; j < N; j++)
            { if (a[i][j] > a[i][j+1]) swap (a[i][j], a[i][j+1]);
            else if (a[i][j] > a[i+1][j]) swap (a[i][j] , a[i+1][j]); }
        }

        for (int i = (N-1); i >= 0; i--)
        {
            for (int j = 0; j < N; j++)
            { fout << a[i][j];
                if (j == (N-1)) fout << endl; }
        }
    fin.close();
    fout.close();
    return 0; 
}
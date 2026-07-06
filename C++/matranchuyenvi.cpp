#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int n ,m, a[100][100];
    ifstream fin ("Matranvao.txt");
    ofstream fout ("Matranra.txt");
    while (! fin.eof()){
        fin >> n >> m;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                fin >> a[i][j];
            }
        }
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            fout << a[j][i] << " ";
        }
        fout << endl;
    }
}
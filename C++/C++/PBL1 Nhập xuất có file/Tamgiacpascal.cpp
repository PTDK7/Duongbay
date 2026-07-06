#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("InPascal.txt");
    ofstream fout("OutPascal.txt");
    int N;

    if (fin >> N) {
        int P[100][100] = {0}; 
        for (int i = 1; i <= (N + 1); i++) {
            for (int j = 1; j <= i; j++) {
                if (j == 1 || j == i) {
                    P[i][j] = 1;
                } else {
                    P[i][j] = P[i - 1][j] + P[i - 1][j - 1];
                }
                fout << P[i][j] << (j == i ? "" : " ");
            }
            fout << endl;
        }
    }

    fin.close();
    fout.close();
    return 0;
}
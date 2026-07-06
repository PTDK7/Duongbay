#include <iostream> 
#include <fstream>
#include <sstream>
using namespace std;

void getMat(string filename, int Mat[][100], int &M, int &N){
    ifstream fin(filename);
    string line;
    N=0; M=0;
    while(getline(fin, line)){
        stringstream ss(line);
        while(ss >> Mat[M][N]) N++;
        M++;
    }
    fin.close();
}

void writeOut(string filename, int Mat[][100], int M, int N){
    ofstream fout(filename);
    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++)
            fout << Mat[i][j] << " ";
        fout << endl;       
    }
    fout.close();
}
void writeOut(string filename, string er){
    ofstream fout(filename);
    fout << er;
    fout.close();
}
int main(){
    int A[100][100];
    int B[100][100];
    int C[100][100];
    int MA, NA, MB, NB;
    
    getMat("Mat1.txt", A, MA, NA);
    getMat("Mat2.txt", B, MB, NB);

    if (MA==MB && NA==NB){
        for (int i=0; i<MA; ++i){
            for (int j=0; j<NA; ++j){
                C[i][j] = A[i][j] + B[i][j];
            }
        }
        writeOut ("MatOut.txt",C,MA,NA);
    } else {
        writeOut("Mat1.txt","Error: Incompatible sizes for this operation");
    }
    return 0;
}

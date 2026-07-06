#include <iostream>
#include <fstream>
using namespace std;

int main (){
    ifstream fin ("InCount.txt");
    ofstream fout ("OutCount.txt");
    int n, k, u;
    int S = 0;
    if (fin >> n >> k){
        int u;
    }
    while (!fin.eof()){
        fin >> u;
        if (u <= k)  S++;
    }
    fout << S;

    fin.close();
    fout.close();
    return 0;
}
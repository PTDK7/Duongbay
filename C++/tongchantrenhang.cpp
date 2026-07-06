#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int n, a[10][10];
    ifstream fin ("Mangvao.txt");
    ofstream fout ("Tongra.txt");

    while (fin >> n){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
                fin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        int s = 0;
        for (int j = 0; j < n; j++)
            if (a[i][j] % 2 == 0)  s += a[i][j];
        fout << "Tong cac so o hang " << i+1 << " la: " << s << endl;
    }

    fin.close();
    fout.close();  
    return 0;
}
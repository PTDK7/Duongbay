#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("expInp.txt");
    ofstream fout("expOut.txt");

    double epsilon;
    int k;
    while (fin >> k){
        epsilon = pow(10, -k);
    double e = 1;         
    double so_hang = 1;   
    int n = 1;            

    while (so_hang >= epsilon) {
        so_hang /= n;       
        e += so_hang;      
        n++;
        so_hang *= n;       

    fout << "Gia tri cua e tinh duoc la: " << e << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
}

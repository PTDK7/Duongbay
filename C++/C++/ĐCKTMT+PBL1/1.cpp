#include <iostream>
#include <fstream>
using namespace std;

float tinh(int x,int n){
    float s=0;
    float k=x+1;
    for (int i=2;i<=n;i++){
        s+=((x+i)/(i*i));
    }
    s=s+k;
    return s;
}
int main(){ 
    ifstream fin("fxInp.txt");
    ofstream fout("fxOut.txt");
    float x;
    float n;
    fin>>n;
    while (fin>>x){
        fout << tinh(x,n)<<endl;
    }
    fout.close();
    fin.close();
    return 0;
}
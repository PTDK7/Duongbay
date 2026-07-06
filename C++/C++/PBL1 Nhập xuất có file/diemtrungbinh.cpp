#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
    ifstream fin ("InDTB.txt");
    ofstream fout ("OutDTB.txt");

    struct ten{
        string a;
    };
    
    struct diemso{
        ten name;
        double b;
        double c;
    };

    diemso ds;
    fout << fixed << setprecision(1);

    while (fin >> ds.name.a >> ds.b >> ds.c)
    {
        fout << ds.name.a << ": " ;
        double k = (ds.b * 0.4 + ds.c * 0.6);
        fout << k << endl;        
    }
    
    fin.close();
    fout.close();
    return 0;
}
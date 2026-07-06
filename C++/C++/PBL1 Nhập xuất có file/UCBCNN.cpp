#include <iostream>
#include <fstream>
using namespace std;

int UCLN (int a, int b)
{
    while (a != b)
    {   if (a > b) a = a - b;
        else b = b - a;
    }
    return a;
}

int BCNN (int a, int b)
{
    int u;
    u = a * b / UCLN(a, b);
    return u;
}

struct so{
    int a;
    int b;
};

so h;

int main (){
    ifstream fin ("InUCLN.txt");
    ofstream fout ("OutUCLN.txt");

    while (fin >> h.a >> h.b)
    {
        fout << UCLN (h.a, h.b) << " ";
        fout << BCNN (h.a, h.b) << endl;
    }
}
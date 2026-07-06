#include <iostream>
#include <fstream>
using namespace std;

struct hangcot {
    int a[100][100];
    int i; //hàng
    int j; //cột
};

hangcot so;

int main (){
    ifstream fin ("InMaxCount.txt");
    ofstream fout ("OutMaxCount.txt");
    while (fin >> so.i >> so.j)
    {   int s = 0;
        for (int u = 1; u <= so.i; u++)
        {
            for (int k = 1; k <= so.j; k++)
            fin >> so.a[u][k];
        }

        for (int u = 1; u <= so.i; u++)
        {
            for (int k = 1; k <= so.j; k++)
            { if (k == 1 && u == 1)
            { if (so.a[u][k] > so.a[u+1][k] && so.a[u][k] > so.a[u+1][k+1] && so.a[u][k] > so.a[u][k+1]) s++;
              else s = s; }
            
              else if (k == 1 && u == so.i)
            { if (so.a[u][k] > so.a[u-1][k] && so.a[u][k] > so.a[u-1][k-1] && so.a[u][k] > so.a[u][k-1]) s++;
              else s = s; }
            
              else if (k == so.j && u == so.i)
            { if (so.a[u][k] > so.a[u-1][k] && so.a[u][k] > so.a[u-1][k-1] && so.a[u][k] > so.a[u][k-1]) s++;
              else s = s; }
            
              else if (k == so.j && u == 1)
            { if (so.a[u][k] > so.a[u+1][k] && so.a[u][k] > so.a[u+1][k-1] && so.a[u][k] > so.a[u][k-1]) s++;
              else s = s; }

              else 
            { if (so.a[u][k] > so.a[u+1][k] && so.a[u][k] > so.a[u+1][k+1] && so.a[u][k] > so.a[u-1][k+1] && so.a[u][k] > so.a[u-1][k] && so.a[u][k] > so.a[u-1][k-1] && so.a[u][k] > so.a[u][k-1] && so.a[u][k] > so.a[u][k+1] && so.a[u][k] > so.a[u+1][k-1]) s++;
              else s = s; }
        }
    }
            fout << s << endl;
}
    fin.close();
    fout.close();
    return 0;
}
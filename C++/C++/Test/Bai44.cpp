#include <iostream>
using namespace std;
void printPascalTriangle(int n) {
int** c = new int*[n];
c[0] = new int[1];
c[0][0] = 1;
for (int i = 1; i < n; ++i) {
c[i] = new int[i];
c[i][0] = 1;
c[i][i] = 1;
for (int j = 1; j <= i; ++j) {
c[i][j] = c[i-1][j-1] + c[i-1][j];
}
}
for (int i = 0; i < n; ++i) {
for (int j = 0; j <= i; ++j) {
cout << c[i][j] << " ";
}
cout << endl;
}
for (int i = 0; i < n; ++i) delete[] c[i];
delete[] c;
}

int main () {
int c[100][100];
int n;
cin >> n;
c[0][0] = 1;
for (int i = 0; i < n; ++i) {
c[i][i] = 1;
c[i][0] = 1;
for (int j = 1; j <= i; ++j) {
c[i][j] = c[i-1][j-1] + c[i-1][j];
}
}
for (int i = 0; i < n; ++i) {
for (int j = 0; j <= i; ++j) cout << c[i][j] << " ";
cout << endl; } } 

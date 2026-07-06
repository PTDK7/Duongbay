#include <iostream>
using namespace std;
int main (){
   int n;
    cout << "Nhap vao 1 so nguyen duong N:"<< endl;
    do { cin >> n;}
    while(n <= 0);
    int a[n][n]; 
    int b[n][n];
    cout << "Nhap vao ma tran A: " << endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> a[i][j];
        }
        cout << endl;
    } 
    cout << "Ma tran B: "<< endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            b[i][j] = a[i][n-1-j];
            cout << b[i][j] <<" ";
        }
        cout<< endl;
    } 
    return 0;
}

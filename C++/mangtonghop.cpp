#include <iostream>
using namespace std;

void tinhtrungbinh (int n, int a[]){
    double s = 0;
    for (int i=0; i<n; i++){
        s += a[i];
    }
    cout << "So trung binh la: " << s/n;
}

int main(){
    int n;
    int a[100];

    cout << "Nhap so phan tu: ";
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    tinhtrungbinh(n, a);
    return 0;
}
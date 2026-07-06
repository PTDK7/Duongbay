#include <iostream>
#include <cmath>
using namespace std;

bool snt(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) { 
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    long long tong = 0;
    int dem = 0;
    cout << "Nhap vao so phan tu N:" << endl;
    cin >> N;
    long long array[N];
    for (int a = 0; a < N; a++) {  
        cin >> array[a];
        if (snt(array[a])) {
            tong += array[a];
            dem++;
        }
    }
    cout << "Tong cac so nguyen to: " << tong << endl;
    cout << "So luong so nguyen to: " << dem << endl;
    return 0;
}

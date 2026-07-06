#include <iostream>
using namespace std;

int main() {
    int n, s;
    int a[100][100];

    do {
        cout << "Nhap n, s: ";
        cin >> n >> s;;
        if (n <= 0 || s <= 0) cout << "Nhap lai!" << endl;
    } while (n <= 0 || s <= 0);

    for (int sum = 0; sum <= 2 * (n - 1); sum++) {
        if (sum % 2 == 0) {
            for (int i = sum; i >= 0; i--) {
                int j = sum - i;
                if (i < n && j < n) {
                    a[i][j] = s++;
                }
            }
        } else {
            for (int i = 0; i <= sum; i++) {
                int j = sum - i;
                if (i < n && j < n) {
                    a[i][j] = s++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
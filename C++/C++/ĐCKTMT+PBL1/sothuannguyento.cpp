#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isDigitPrime(int n) {
    string s = to_string(n);
    for (char c : s) {
        if (c != '2' && c != '3' && c != '5' && c != '7') {
            return false;
        }
    }
    return true;
}

int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int countPurePrime(int a, int b) {
    int count = 0;
    for (int num = a; num <= b; num++) {
        if (!isPrime(num)) continue;
        if (!isDigitPrime(num)) continue;
        if (!isPrime(sumOfDigits(num))) continue;
        count++;
    }
    return count;
}

int main() {
    int a, b;
    cout << "Nhap 2 so a va b: ";
    cin >> a >> b;
    cout << countPurePrime(a, b);
    return 0;
}
#include <iostream>
#include <math.h>
using namespace std;    

void vitri(int n, int a[100]){
    cout << "Cac so chan o vi tri le la: ";
    for (int i=0; i<n; i++) {
        if ((i+1)%2 !=0) 
        {
            if (a[i]%2==0) cout << a[i] << " ";
        }
    }
}

void sochinhphuong(int n, int a[100]){
    int s = 0;
    for (int i=0; i<n; i++) {
        int k = sqrt(a[i]);
        if (k * k == a[i]) s += a[i];
        else s += 0;
    }
    cout << "Tong cac so chinh phuong la: " << s;
}


int main()
{
    int n;
    int a[100];
    do {
        cout << "Nhap so phan tu: ";
        cin >> n;
    } while (n < 1 || n > 100);
    
    for (int i=0; i<n; i++)
        cin >> a[i];
    vitri(n, a);
    cout << endl;
    sochinhphuong(n, a);
    return 0;
}
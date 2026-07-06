#include<iostream>
#include<math.h>
using namespace std;

long long BT51(int m , int n, int arr[99][99]){
    for(int i = 0 ; i < m ; i+=2){
        long long s = 0 ;
        for(int j = 0 ; j < n ; j++){
            s = s + arr[i][j];
            }
            cout <<"tong hang "<< i << " la " << s << endl;
        }    return 0 ;
}
long long BT52(int n , int m, int arr[99][99]){
    for(int i = 1 ; i < n ; i+=2){
        long long s = 0 ;
        for(int j = 0 ; j < n ; j++){
            s = s + arr[i][j];
            }
            cout <<"tong cot "<< i << " la " << s << endl;
        }    return 0 ;
}

int main(){
    int n , m;
    int s = 0 ;
    cin >> m >> n;
    int arr[99][99];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Nhap phan tu arr[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
    BT51(m , n , arr);
    BT52(n , m , arr);    
return 0 ;
}
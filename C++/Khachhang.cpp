#include<iostream>
using namespace std;

struct Hoten {
    string ho;
    string tendem;
    string ten;
};

struct GiaoVien {
    Hoten hoten;
    int MaGV;
    double HeSoLuong;
    double PhuCap;
};



void Nhap(Hoten &GV){
    cout << "Nhap ho: ";
    cin >> GV.ho;
    cout << "Nhap ten dem: ";
    cin >> GV.tendem;
    cout << "Nhap ten: ";
    cin >> GV.ten;
}

void luong(GiaoVien &GV1){
    cout << "Nhap MaGV: ";
    cin >> GV1.MaGV;
    cout << "Nhap HeSoLuong: ";
    cin >> GV1.HeSoLuong;
    cout << "Nhap PhuCap: ";
    cin >> GV1.PhuCap;
}

void tinhluong(GiaoVien &GV1){
    long long luong = GV1.HeSoLuong * 1800000 + GV1.PhuCap;
    cout << "Luong cua giao vien la: " << luong;
}

int main(){
    Hoten GV;
    GiaoVien GV1;
    Nhap(GV);
    luong(GV1);
    tinhluong(GV1);
    return 0;
}
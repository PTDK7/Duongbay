#include <iostream>
using namespace std;

struct NgayThang{
    int ngay;
    int thang;
    int nam;
};

struct sach{
    string masach;
    string tensach;
    NgayThang ngayMuon;
    int soTrang;
    string nguoimuon;
};

void nhap(int &n, sach s[100]){
    cout << "Nhap ten nguoi muon sach: ";
    cin >> s[n].nguoimuon;
    cout << "Nhap ma sach: ";
    cin >> s[n].masach;
    cout << "Nhap ten sach: ";
    cin >> s[n].tensach;
    cout << "Nhap ngay muon (ngay thang nam): ";
    cin >> s[n].ngayMuon.ngay >> s[n].ngayMuon.thang >> s[n].ngayMuon.nam;
    cout << "Nhap so trang: ";
    cin >> s[n].soTrang;
}

void xuatdulieu(int n, sach s[100]){
    cout << "Nguoi muon sach: " << s[n].nguoimuon << endl;
    cout << "Ma sach: " << s[n].masach << endl;
    cout << "Ten sach: " << s[n].tensach << endl;
    cout << "Ngay muon: " << s[n].ngayMuon.ngay << "/" << s[n].ngayMuon.thang << "/" << s[n].ngayMuon.nam << endl;
}

void sapxep(int n, sach s[100]){
    int a_max = s[0].soTrang;
    for (int i=1; i<n; i++){
        if (s[i].soTrang > a_max) a_max = s[i].soTrang;
        else a_max = a_max;
    }
    cout << "Sach co so trang lon nhat la: " << a_max << endl;
}


int main(){
    int n;
    cout << "Nhap so luong nguoi muon sach: ";
    cin >> n;
    sach s[100];

    for (int i=0; i<n; i++) {
        cout << "Nhap thong tin nguoi muon sach thu " << i+1 << ":" << endl;
        nhap(i, s);
    }

    for (int i=0; i<n; i++) {
        cout << "Thong tin nguoi muon sach thu " << i+1 << ":" << endl;
        xuatdulieu(i, s);
        cout << endl;
    }

        sapxep(n, s);

    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class DailyRecord {
private:
    string dayName;     
    int caloConsumed;  

public:
    DailyRecord() {
        dayName = "";
        caloConsumed = 0;
    }

    DailyRecord(string name, int calo) {
        dayName = name;
        caloConsumed = calo;
    }

    string getDayName() const {
        return dayName;
    }

    int getCaloConsumed() const {
        return caloConsumed;
    }
};

class WeeklyTracker {
private:
    int targetCalo;                 
    vector<DailyRecord> records;   

public:
    WeeklyTracker(int target) {
        targetCalo = target;
    }

    void addRecord(const DailyRecord& r) {
        records.push_back(r);
    }


    int tinhTongCalo() const {
        int tong = 0;
        for (const auto& r : records) {
            tong += r.getCaloConsumed();
        }
        return tong;
    }


    void inThongKe() const {
        if (records.empty()) {
            cout << "Chua co du lieu thong ke!" << endl;
            return;
        }

        int tongCalo = tinhTongCalo();
        double trungBinh = (double)tongCalo / records.size();

        DailyRecord maxDay = records[0];
        DailyRecord minDay = records[0];

        for (size_t i = 1; i < records.size(); i++) {
            if (records[i].getCaloConsumed() > maxDay.getCaloConsumed()) {
                maxDay = records[i];
            }
            if (records[i].getCaloConsumed() < minDay.getCaloConsumed()) {
                minDay = records[i];
            }
        }

        // --- IN KẾT QUẢ ---
        cout << "\n--- THONG KE TUAN ---" << endl;
        cout << "Tong calo da nap: " << tongCalo << " kcal" << endl;
        // In số thập phân làm tròn đến 1 chữ số sau dấu phẩy
        cout << fixed << setprecision(1);
        cout << "Trung binh/ngay: " << trungBinh << " kcal" << endl;
        cout << endl;

        cout << "Ngay nap nhieu nhat: " << maxDay.getDayName() 
             << " (" << maxDay.getCaloConsumed() << " kcal)" << endl;
        cout << "Ngay nap it nhat: " << minDay.getDayName() 
             << " (" << minDay.getCaloConsumed() << " kcal)" << endl;
        cout << endl;

        cout << "Canh bao vuot muc tieu (" << targetCalo << " kcal):" << endl;
        bool coVuotMuc = false;
        
        for (const auto& r : records) {
            if (r.getCaloConsumed() > targetCalo) {
                coVuotMuc = true;
                int chenhLech = r.getCaloConsumed() - targetCalo;
                cout << "+ " << r.getDayName() << ": vuot " << chenhLech << " kcal" << endl;
            }
        }

        // Trường hợp không có ngày nào vượt mục tiêu cả
        if (!coVuotMuc) {
            cout << "Tuyet voi! Khong co ngay nao vuot muc tieu." << endl;
        }
    }
};

// ==========================================
// 3. HÀM MAIN (ĐIỀU KHIỂN CHƯƠNG TRÌNH)
// ==========================================
int main() {
    int target;
    // Nhập mục tiêu calo hàng ngày
    cin >> target;

    // Khởi tạo đối tượng quản lý tuần với mục tiêu đã nhập
    WeeklyTracker tracker(target);

    // Vòng lặp nhập dữ liệu cho 7 ngày
    for (int i = 0; i < 7; i++) {
        string name;
        int calo;
        cin >> name >> calo;

        // Tạo một object đại diện cho dữ liệu của ngày hiện tại
        DailyRecord r(name, calo);
        
        // Đưa object ngày này vào tracker để quản lý
        tracker.addRecord(r);
    }

    // Yêu cầu đối tượng tracker tính toán và in toàn bộ báo cáo
    tracker.inThongKe();

    return 0;
}
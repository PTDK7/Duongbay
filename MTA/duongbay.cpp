#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

// --- 1. KHAI BÁO HẰNG SỐ VẬT LÝ ---
const double G = 9.81;              // Gia tốc trọng trường (m/s^2)
const double PI = 3.14159265358979;
const double RHO_AIR = 1.225;       // Khối lượng riêng không khí (kg/m^3)

int main() {
    // --- 2. THÔNG SỐ ĐẦU VÀO CỦA VIÊN ĐẠN ---
    double v0;       // Vận tốc đầu SIÊU CAO (m/s) -> Giúp giai đoạn đầu bay thẳng tắp
    double alpha;     // Góc bắn (độ)
    double mass;      // Khối lượng viên đạn (10g = 0.01kg)
    double diameter = 0.009; // Đường kính đạn 9mm (0.009m)
    double Cd = 0.1;         // Hệ số cản khí động học của đầu đạn nhọn

    cout << "Nhap van toc ban dau (m/s): ";
    cin >> v0;
    cout << "Nhap goc ban (do): ";
    cin >> alpha;
    cout << "Nhap khoi luong vien dan (kg): ";
    cin >> mass;


    // Tính toán các hằng số phụ trợ
    double area = PI * (diameter / 2.0) * (diameter / 2.0);
    double drag_const = 0.5 * RHO_AIR * Cd * area / mass;

    // Chuyển góc sang Radian
    double alpha_rad = alpha * PI / 180.0;

    // Trạng thái ban đầu: Toạ độ (x, y) và Vận tốc (vx, vy)
    double x = 0.0;
    double y = 0.0;
    double vx = v0 * cos(alpha_rad);
    double vy = v0 * sin(alpha_rad);

    // Cấu hình bước thời gian mô phỏng (càng nhỏ càng chính xác)
    double dt = 0.001; // 1 mili-giây một bước
    
    // Khởi tạo vector lưu trữ toàn bộ đường bay
    struct Point3D { double x, y, z; };
    vector<Point3D> trajectory;

    cout << "Dang tinh toan duong bay thuc te..." << endl;

    // --- 3. GIẢI PHƯƠNG TRÌNH VI PHÂN BẰNG PHƯƠNG PHÁP EULER ---
    while (y >= 0.0) {
        // Lưu tọa độ hiện tại (Trục Z mô phỏng bằng 0 vì đạn bay thẳng theo hướng bắn)
        trajectory.push_back({x, y, 0.0});

        // Nếu bắn quá xa hoặc lỗi vòng lặp an toàn
        if (trajectory.size() > 500000) break;

        // Vận tốc tổng hợp hiện tại
        double v = sqrt(vx * vx + vy * vy);

        // Tính gia tốc lực cản (ngược chiều vận tốc)
        double ax = - drag_const * v * vx;
        double ay = - drag_const * v * vy - G; // Lực cản + Trọng lực

        // Cập nhật tọa độ mới
        x += vx * dt;
        y += vy * dt;

        // Cập nhật vận tốc mới
        vx += ax * dt;
        vy += ay * dt;
    }

    // In thông số kết quả ra màn hình Console
    cout << "\n--- KET QUA MO PHONG CO LUC CAN KHI DONG ---" << endl;
    cout << fixed << setprecision(2);
    cout << "Tam xa dat duoc: " << x << " met." << endl;
    cout << "Thoi gian bay thuc te: " << trajectory.size() * dt << " giay." << endl;

    // --- 4. XUẤT FILE MÔ HÌNH 3D (.OBJ) ---
    string filename = "duong_bay_3d.obj";
    ofstream obj_file(filename);

    if (obj_file.is_open()) {
        obj_file << "# Mo hinh 3D duong bay vien dan tao boi C++\n";
        
        // Xuất các đỉnh (Vertices) trong không gian 3D. 
        // Lưu ý: Trong đồ họa 3D, thông thường Y là trục thẳng đứng (độ cao), Z là trục chiều sâu.
        // Nên ta đổi chỗ: X_3d = x, Y_3d = y (độ cao), Z_3d = z (bằng 0).
        for (const auto& pt : trajectory) {
            obj_file << "v " << pt.x << " " << pt.y << " " << pt.z << "\n";
        }

        // Xuất đường nối các đỉnh (Line/Edge) để tạo thành một sợi dây 3D liên tục
        obj_file << "l";
        for (size_t i = 1; i <= trajectory.size(); ++i) {
            obj_file << " " << i;
        }
        obj_file << "\n";

        obj_file.close();
        cout << "\nDA XUAT FILE MO HINH 3D THANH CONG: " << filename << endl;
        cout << "Ban co thể mo file nay bang phan mem 3D Viewer co san tren Windows hoac Blender." << endl;
    } else {
        cout << "Khong the tao file .obj!" << endl;
    }

    return 0;
}
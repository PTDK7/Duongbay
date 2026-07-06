import os
import sys
import readchar

# Cấu hình màu sắc hiển thị trên Terminal bằng mã ANSI (Giúp giao diện CLI sinh động)
MAU_XANH_DUONG = "\033[34m"
MAU_VANG = "\033[33m"
MAU_DO = "\033[31m"
MAU_NGUOI_CHOI = "\033[36m\033[1m" # Xanh neon đậm
MAU_XANH_LA = "\033[32m"
MAU_GOC = "\033[0m"

class TuyetDoiChiLenhCLI:
    def __init__(self):
        # Định nghĩa ma trận bản đồ 3 tầng (5x5) giống Siêu Trí Tuệ
        # ".": Ô Trống, "Y": Ô Vàng, Số (1-3): Ô số lượt đi, "R": Ô đỏ mặc định
        self.cau_hinh_ban_do = [
            # TẦNG 1
            [
                [".", "2", ".", ".", "Y"],
                [".", ".", ".", "Y", "."],
                ["1", ".", ".", ".", "."],
                [".", "Y", ".", ".", "2"],
                [".", ".", ".", ".", "."]
            ],
            # TẦNG 2
            [
                [".", "Y", ".", ".", "."],
                [".", ".", "1", ".", "."],
                [".", ".", "Y", ".", "3"],
                [".", "2", ".", ".", "."],
                ["Y", ".", ".", ".", "."]
            ],
            # TẦNG 3
            [
                [".", ".", ".", "Y", "."],
                [".", ".", ".", ".", "."],
                ["2", ".", ".", ".", "1"],
                [".", ".", ".", "Y", "."],
                [".", ".", "1", ".", "."]
            ]
        ]
        self.dat_lai_tro_choi()

    def dat_lai_tro_choi(self):
        self.tang_hien_tai = 0
        self.vi_tri_x = 0  # Cột
        self.vi_tri_y = 0  # Dòng
        self.so_buoc = 0
        self.cac_o_da_qua = set()
        self.cac_o_da_qua.add((self.tang_hien_tai, self.vi_tri_y, self.vi_tri_x))

        # Khởi tạo bản đồ tính toán động
        self.ban_do = []
        for t in range(3):
            tang = []
            for r in range(5):
                dong = []
                for c in range(5):
                    val = self.cau_hinh_ban_do[t][r][c]
                    dong.append(int(val) if val.isdigit() else val)
                tang.append(dong)
            self.ban_do.append(tang)

    def xoa_man_hinh(self):
        # Tự động xóa màn hình Terminal cũ tùy theo hệ điều hành (Windows/Linux/macOS)
        os.system('cls' if os.name == 'nt' else 'clear')

    def hien_thi_giao_dien(self):
        self.xoa_man_hinh()
        print(f"=== SIÊU TRÍ TUỆ: TUYỆT ĐỐI CHỈ LỆNH ===")
        print(f"Số lệnh đã nhập: {MAU_VANG}{self.so_buoc}{MAU_GOC}")
        print(f"Tầng bạn đang đứng: {MAU_XANH_DUONG}TẦNG {self.tang_hien_tai + 1}{MAU_GOC}\n")

        # In đồng thời cả 3 tầng theo hàng ngang để người chơi dễ quan sát không gian 3D
        for r in range(5):
            dong_hien_thi = []
            for t in range(3):
                o_trong_tang = []
                for c in range(5):
                    cell = self.ban_do[t][r][c]
                    
                    # Nếu người chơi đang đứng ở ô này
                    if t == self.tang_hien_tai and r == self.vi_tri_y and c == self.vi_tri_x:
                        o_trong_tang.append(f"{MAU_NGUOI_CHOI} P {MAU_GOC}")
                    elif cell == "Y":
                        o_trong_tang.append(f"{MAU_VANG} Y {MAU_GOC}")
                    elif cell == "R" or cell == 0:
                        o_trong_tang.append(f"{MAU_DO} X {MAU_GOC}") # X biểu thị ô Đỏ bị chặn
                    elif isinstance(cell, int) and cell > 0:
                        o_trong_tang.append(f"{MAU_XANH_DUONG} {cell} {MAU_GOC}")
                    else:
                        o_trong_tang.append(" . ")
                
                # Nối các ô trong một dòng của tầng t lại với nhau
                dong_hien_thi.append("[" + "".join(o_trong_tang) + "]")
            
            # In dòng r của cả 3 tầng kề nhau
            print("   ".join(dong_hien_thi))
        
        print("\n" + "="*40)
        print("HƯỚNG DẪN CHƠI:")
        print("• Dùng phím Mũi Tên để di chuyển (Trượt tự do).")
        print(f"• Bấm {MAU_XANH_LA}W{MAU_GOC} để LÊN tầng | Bấm {MAU_XANH_LA}S{MAU_GOC} để XUỐNG tầng.")
        print("• Bấm R để chơi lại từ đầu | Bấm Q để thoát.")
        print(f"Chú thích: {MAU_NGUOI_CHOI}P{MAU_GOC}: Bạn | {MAU_VANG}Y{MAU_GOC}: Ô vàng | {MAU_DO}X{MAU_GOC}: Ô Đỏ bị chặn.")

        if self.kiem_tra_thang():
            print(f"\n{MAU_XANH_LA}-> CHÚC MỪNG! BẠN ĐÃ ĐI QUA TẤT CẢ CÁC Ô VÀ CHIẾN THẮNG!{MAU_GOC}")

    def di_chuyen(self, h_x, h_y):
        x, y = self.vi_tri_x, self.vi_tri_y
        t = self.tang_hien_tai
        da_di_chuyen = False

        while True:
            tiep_x = x + h_x
            tiep_y = y + h_y

            if not (0 <= tiep_x < 5 and 0 <= tiep_y < 5):
                break

            o_tiep = self.ban_do[t][tiep_y][tiep_x]
            if o_tiep == 0 or o_tiep == "R":
                break

            x, y = tiep_x, tiep_y
            da_di_chuyen = True
            self.cac_o_da_qua.add((t, y, x))

            if isinstance(self.ban_do[t][y][x], int) and self.ban_do[t][y][x] > 0:
                self.ban_do[t][y][x] -= 1

            if o_tiep == "Y":
                break

        if da_di_chuyen:
            self.vi_tri_x = x
            self.vi_tri_y = y
            self.so_buoc += 1

    def doi_tang(self, huong_tang):
        tang_moi = self.tang_hien_tai + huong_tang
        if 0 <= tang_moi < 3:
            o_tang_moi = self.ban_do[tang_moi][self.vi_tri_y][self.vi_tri_x]
            if o_tang_moi != "R" and o_tang_moi != 0:
                self.tang_hien_tai = tang_moi
                self.so_buoc += 1
                self.cac_o_da_qua.add((self.tang_hien_tai, self.vi_tri_y, self.vi_tri_x))
                if isinstance(self.ban_do[tang_moi][self.vi_tri_y][self.vi_tri_x], int) and self.ban_do[tang_moi][self.vi_tri_y][self.vi_tri_x] > 0:
                    self.ban_do[tang_moi][self.vi_tri_y][self.vi_tri_x] -= 1

    def kiem_tra_thang(self):
        return len(self.cac_o_da_qua) == (3 * 5 * 5)

    def vao_luong_choi(self):
        while True:
            self.hien_thi_giao_dien()
            if self.kiem_tra_thang():
                # Nếu thắng thì dừng chờ bấm R để chơi lại hoặc Q để thoát
                ky_tu = readchar.readchar()
                if ky_tu.lower() == 'r': self.dat_lai_tro_choi()
                elif ky_tu.lower() == 'q': break
                continue

            # Đọc tín hiệu phím bấm thời gian thực
            ky_tu = readchar.readkey()

            if ky_tu == readchar.key.UP:
                self.di_chuyen(0, -1)
            elif ky_tu == readchar.key.DOWN:
                self.di_chuyen(0, 1)
            elif ky_tu == readchar.key.LEFT:
                self.di_chuyen(-1, 0)
            elif ky_tu == readchar.key.RIGHT:
                self.di_chuyen(1, 0)
            elif ky_tu.lower() == 'w':
                self.doi_tang(1)
            elif ky_tu.lower() == 's':
                self.doi_tang(-1)
            elif ky_tu.lower() == 'r':
                self.dat_lai_tro_choi()
            elif ky_tu.lower() == 'q':
                break

if __name__ == "__main__":
    # Đảm bảo mã màu ANSI hoạt động chính xác trên Windows Terminal
    if os.name == 'nt':
        os.system('')
        
    game = TuyetDoiChiLenhCLI()
    game.vao_luong_choi()
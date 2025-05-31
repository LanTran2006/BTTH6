#include "nhanvien.h"

int main() {
    QuanLyNhanVien ql;
    ql.nhap();

    cout << "\nDanh sach nhan vien:\n";
    ql.xuat();

    cout << "\nTong luong: " << ql.tinhTongLuong() << endl;
    
    ql.nhanVienSanXuatLuongThapNhat();
    ql.nhanVienVanPhongTuoiCaoNhat();

    return 0;
}

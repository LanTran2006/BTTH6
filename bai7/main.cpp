#include "bai7.h"

int main() {
    vector<NhanVienVP> danhSach;

    // Nhập danh sách nhân viên
    NhanVienVP::nhapDanhSach(danhSach);

    // Xuất danh sách nhân viên
    NhanVienVP::xuatDanhSach(danhSach);

    // Tìm nhân viên có lương cao nhất
    cout << "\nNhan vien co luong cao nhat:\n";
    NhanVienVP::timNhanVienLuongCaoNhat(danhSach).xuat();

    // Tính tổng lương
    cout << "\nTong luong phai tra: " << NhanVienVP::tinhTongLuong(danhSach) << endl;

    // Tìm nhân viên lớn tuổi nhất
    cout << "\nNhan vien co tuoi cao nhat:\n";
    NhanVienVP::timNhanVienTuoiCaoNhat(danhSach).xuat();

    // Sắp xếp danh sách theo lương tăng dần
    NhanVienVP::sapXepLuongTangDan(danhSach);
    cout << "\nDanh sach sau khi sap xep theo luong tang dan:\n";
    NhanVienVP::xuatDanhSach(danhSach);

    return 0;
}

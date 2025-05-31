#include <bits/stdc++.h>
#include "nhanvien.h"
using namespace std;

void NhanVien::nhap() {
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    getline(cin, ngaySinh);
}

void NhanVien::xuat() {
    cout << fixed << setprecision(2);
    cout << "Ho ten: " << hoTen
         << ", Ngay sinh: " << ngaySinh
         << ", Luong: " << luong << endl;
}

int NhanVien::tuoi() {
    int namSinh = stoi(ngaySinh.substr(6));
    time_t now = time(0);
    tm* ltm = localtime(&now);
    return 1900 + ltm->tm_year - namSinh;
}

void NhanVienVanPhong::nhap() {
    NhanVien::nhap();
    cout << "Nhap so ngay lam viec: ";
    cin >> soNgayLamViec;
    cin.ignore();
    tinhLuong();
}

void NhanVienVanPhong::tinhLuong() {
    luong = soNgayLamViec * 100000;
}

LoaiNhanVien NhanVienVanPhong::getLoai() {
    return VAN_PHONG;
}

void NhanVienSanXuat::nhap() {
    NhanVien::nhap();
    cout << "Nhap luong co ban: ";
    cin >> luongCoBan;
    cout << "Nhap so san pham: ";
    cin >> soSanPham;
    cin.ignore();
    tinhLuong();
}

void NhanVienSanXuat::tinhLuong() {
    luong = luongCoBan + soSanPham * 5000;
}

LoaiNhanVien NhanVienSanXuat::getLoai() {
    return SAN_XUAT;
}

void QuanLyNhanVien::nhap() {
    int n, loai;
    cout << "Nhap so nhan vien: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        cout << "1. Nhan vien san xuat, 2. Nhan vien van phong: ";
        cin >> loai;
        cin.ignore();

        NhanVien* nv;
        if (loai == 1) nv = new NhanVienSanXuat();
        else nv = new NhanVienVanPhong();

        nv->nhap();
        danhSach.push_back(nv);
    }
}

void QuanLyNhanVien::xuat() {
    for (int i = 0; i < danhSach.size(); ++i) {
        danhSach[i]->xuat();
    }
}

double QuanLyNhanVien::tinhTongLuong() {
    double tong = 0;
    for (int i = 0; i < danhSach.size(); ++i) {
        tong += danhSach[i]->luong;
    }
    return tong;
}

void QuanLyNhanVien::nhanVienSanXuatLuongThapNhat() {
    NhanVien* minNV = nullptr;
    for (int i = 0; i < danhSach.size(); ++i) {
        if (danhSach[i]->getLoai() == SAN_XUAT) {
            if (minNV == nullptr || danhSach[i]->luong < minNV->luong) {
                minNV = danhSach[i];
            }
        }
    }
    if (minNV != nullptr) {
        cout << "Nhan vien san xuat co luong thap nhat:\n";
        minNV->xuat();
    }
}

void QuanLyNhanVien::nhanVienVanPhongTuoiCaoNhat() {
    NhanVien* maxNV = nullptr;
    for (int i = 0; i < danhSach.size(); ++i) {
        if (danhSach[i]->getLoai() == VAN_PHONG) {
            if (maxNV == nullptr || danhSach[i]->tuoi() > maxNV->tuoi()) {
                maxNV = danhSach[i];
            }
        }
    }
    if (maxNV != nullptr) {
        cout << "Nhan vien van phong co tuoi cao nhat:\n";
        maxNV->xuat();
    }
}

QuanLyNhanVien::~QuanLyNhanVien() {
    for (int i = 0; i < danhSach.size(); ++i) {
        delete danhSach[i];
    }
}

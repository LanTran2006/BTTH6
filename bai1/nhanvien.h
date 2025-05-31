#ifndef NHANVIEN_H_INCLUDED
#define NHANVIEN_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;

enum LoaiNhanVien { VAN_PHONG, SAN_XUAT };

class NhanVien {
protected:
    string hoTen;
    string ngaySinh;
public:
    double luong;
    virtual void nhap();
    virtual void xuat();
    virtual void tinhLuong() = 0;
    virtual int tuoi();
    virtual LoaiNhanVien getLoai() = 0;
    virtual ~NhanVien() {}
};

class NhanVienSanXuat : public NhanVien {
    int soSanPham;
    double luongCoBan;
public:
    void nhap();
    void tinhLuong();
    LoaiNhanVien getLoai();
};

class NhanVienVanPhong : public NhanVien {
    int soNgayLamViec;
public:
    void nhap();
    void tinhLuong();
    LoaiNhanVien getLoai();
};

class QuanLyNhanVien {
    vector<NhanVien*> danhSach;
public:
    void nhap();
    void xuat();
    double tinhTongLuong();
    void nhanVienSanXuatLuongThapNhat();
    void nhanVienVanPhongTuoiCaoNhat();
    ~QuanLyNhanVien();
};

#endif // NHANVIEN_H_INCLUDED

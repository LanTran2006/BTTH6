#ifndef SINHVIEN_H_INCLUDED
#define SINHVIEN_H_INCLUDED

#include <bits/stdc++.h>
using namespace std;

class SinhVien {
protected:
    string maSV, hoTen, diaChi;
    int tongTinChi;
    float diemTB;

public:
    virtual void nhap();
    virtual void xuat();
    virtual bool totNghiep() = 0;
    float getDiemTB();
    virtual string loai() = 0;
    virtual ~SinhVien() {}
};

class SinhVienCaoDang : public SinhVien {
    float diemTN;

public:
    void nhap();
    void xuat();
    bool totNghiep();
    string loai();
};

class SinhVienDaiHoc : public SinhVien {
    string tenLuanVan;
    float diemLuanVan;

public:
    void nhap();
    void xuat();
    bool totNghiep();
    string loai();
};

class QuanLySinhVien {
    vector<SinhVien*> ds;

public:
    ~QuanLySinhVien();
    void nhapDanhSach();
    void xuatDanhSach();
    void xuatTotNghiep();
    void xuatKhongTotNghiep();
    void sinhVienDiemTBCaoNhat();
    void thongKeKhongTotNghiep();
};


#endif // SINHVIEN_H_INCLUDED

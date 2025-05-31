#ifndef CONGTY_H_INCLUDED
#define CONGTY_H_INCLUDED

#include<bits/stdc++.h>
using namespace std;

class NhanVien {
protected:
    string maNV, hoTen, sdt, email;
    int tuoi;
    double luongCoBan;
public:
    virtual void nhap();
    virtual void xuat();
    virtual double tinhLuong() = 0;
    virtual bool laLapTrinhVien() = 0;
    virtual ~NhanVien() {}
};

class LapTrinhVien : public NhanVien {
    int soGioOT;
public:
    void nhap();
    void xuat();
    double tinhLuong();
    bool laLapTrinhVien();
};

class KiemChungVien : public NhanVien {
    int soLoiPhatHien;
public:
    void nhap();
    void xuat();
    double tinhLuong();
    bool laLapTrinhVien();
};

class CongTy {
    vector<NhanVien*> danhSach;
public:
    void nhapDanhSach();
    void xuatDanhSach();
    void xuatLuongThapHonTB();
    void xuatLuongCaoNhat();
    void xuatLuongThapNhat();
    void xuatLapTrinhLuongCaoNhat();
    void xuatKiemChungLuongThapNhat();
    ~CongTy();
};

#endif // CONGTY_H_INCLUDED

#ifndef KHACHHANG_H_INCLUDED
#define KHACHHANG_H_INCLUDED

#include <bits/stdc++.h>
using namespace std;

class KhachHang {
protected:
    string ten;
    int soLuong;
    int donGia;
public:
    virtual void nhap(ifstream &in);
    virtual void xuat(ofstream &out);
    virtual double tinhTien() = 0;
    virtual ~KhachHang() {}
};

// Loại A: khách hàng bình thường
class KhachHangA : public KhachHang {
public:
    double tinhTien();
};

// Loại B: khách hàng thân thiết
class KhachHangB : public KhachHang {
    int soNam;
public:
    void nhap(ifstream &in);
    double tinhTien();
};

// Loại C: khách hàng đặc biệt
class KhachHangC : public KhachHang {
public:
    double tinhTien();
};

// Lớp quản lý công ty
class CongTy {
    vector<KhachHang*> danhSach;
    int x, y, z;
public:
    void docFile(string tenFile);
    void ghiFile(string tenFile);
    ~CongTy();
};


#endif // KHACHHANG_H_INCLUDED

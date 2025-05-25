#ifndef GIAODICH_H_INCLUDED
#define GIAODICH_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;

class GiaoDich {
protected:
    string maGD, ngayGD;
    double donGia, soLuong;

public:
    void nhap();
    void xuat();
    double getDonGia();
    double getSoLuong();
};

class GiaoDichVang : public GiaoDich {
    string loaiVang;

public:
    void nhap();
    void xuat();
    double tinhThanhTien();
};

class GiaoDichTienTe : public GiaoDich {
    string loaiTien;
    double tiGia;

public:
    void nhap();
    void xuat();
    double tinhThanhTien();
    string getLoaiTien();
};

class QuanLyGiaoDich {
    vector<GiaoDichVang> dsVang;
    vector<GiaoDichTienTe> dsTienTe;

public:
    void nhapDanhSachVang();
    void nhapDanhSachTienTe();
    void xuatGiaoDichVangMax();
    void xuatGiaoDichEuroMin();
    void xuatGiaoDichTren1Ty();
};

#endif // GIAODICH_H_INCLUDED

#ifndef GIAODICH_H_INCLUDED
#define GIAODICH_H_INCLUDED

#include <bits/stdc++.h>
using namespace std;

class GiaoDich {
protected:
    string maGD, ngay;
    double donGia, dienTich;
public:
    void nhap();
    void xuat();
    string getNgay();
    double thanhTien();
};

class GiaoDichDat : public GiaoDich {
    char loaiDat;
public:
    void nhap();
    void xuat();
    double thanhTien();
};

class GiaoDichNhaPho : public GiaoDich {
    string loaiNha, diaChi;
public:
    void nhap();
    void xuat();
    double thanhTien();
};

class GiaoDichCanHo : public GiaoDich {
    string maCan;
    int viTriTang;
public:
    void nhap();
    void xuat();
    double thanhTien();
};

bool laThang12Nam2024(string ngay);

class QuanLyGiaoDich {
    vector<GiaoDichDat> dsDat;
    vector<GiaoDichNhaPho> dsNha;
    vector<GiaoDichCanHo> dsCan;
public:
    void nhapGiaoDich();
    void xuatThongKeSoLuong();
    void xuatTrungBinhCanHo();
    void xuatNhaPhoMax();
    void xuatThang12Nam2024();
};

#endif // GIAODICH_H_INCLUDED

#ifndef BAI7_H_INCLUDED
#define BAI7_H_INCLUDED

#include <bits/stdc++.h>
using namespace std;

class NhanVienVP {
private:
    string maNV;
    string hoTen;
    string ngaySinh;
    double luong;

public:
    NhanVienVP();
    NhanVienVP(string maNV, string hoTen, string ngaySinh, double luong);

    void nhap();
    void xuat() const;

    double getLuong() const;
    string getNgaySinh() const;

    static void nhapDanhSach(vector<NhanVienVP>& danhSach);
    static void xuatDanhSach(const vector<NhanVienVP>& danhSach);
    static NhanVienVP timNhanVienLuongCaoNhat(const vector<NhanVienVP>& danhSach);
    static double tinhTongLuong(const vector<NhanVienVP>& danhSach);
    static NhanVienVP timNhanVienTuoiCaoNhat(const vector<NhanVienVP>& danhSach);
    static void sapXepLuongTangDan(vector<NhanVienVP>& danhSach);
};

#endif // BAI7_H_INCLUDED

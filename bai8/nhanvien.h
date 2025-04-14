#ifndef NHANVIEN_H_INCLUDED
#define NHANVIEN_H_INCLUDED

#include <bits/stdc++.h>
using namespace std;

struct Date {
    int ngay, thang, nam;
    void nhap();
    void xuat() const;
    int tinhTuoi() const;
    bool treHon(const Date& other) const;
};

class cNhanVienSX {
private:
    string maNV, hoTen;
    Date ngaySinh;
    int soSP;
    float donGia;

public:
    void nhap();
    void xuat() const;
    float tinhLuong() const;
    int getTuoi() const;
    bool treHonNguoiKhac(const cNhanVienSX& other) const;
    static void nhapDanhSach(vector<cNhanVienSX>& ds);
    static void xuLyDanhSach(vector<cNhanVienSX>& ds);
    static void xuatDanhSach(const vector<cNhanVienSX>& ds);
    static cNhanVienSX timLuongThapNhat(const vector<cNhanVienSX>& ds);
    static float tongLuong(const vector<cNhanVienSX>& ds);
    static cNhanVienSX timNguoiGiaNhat(const vector<cNhanVienSX>& ds);
    static void sapXepTheoLuong(vector<cNhanVienSX>& ds);
};


#endif // NHANVIEN_H_INCLUDED

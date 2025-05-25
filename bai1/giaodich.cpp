#include "giaodich.h"

void GiaoDich::nhap() {
    cout << "Ma GD: "; cin >> maGD;
    cout << "Ngay GD: "; cin >> ngayGD;
    cout << "Don gia: "; cin >> donGia;
    cout << "So luong: "; cin >> soLuong;
}

void GiaoDich::xuat() {
    cout << "Ma GD: " << maGD
         << ", Ngay: " << ngayGD
         << ", Don gia: " << donGia
         << ", So luong: " << soLuong;
}

double GiaoDich::getDonGia() {
    return donGia;
}

double GiaoDich::getSoLuong() {
    return soLuong;
}

void GiaoDichVang::nhap() {
    GiaoDich::nhap();
    cout << "Loai vang: "; cin >> loaiVang;
}

void GiaoDichVang::xuat() {
    GiaoDich::xuat();
    cout << ", Loai vang: " << loaiVang
         << ", Thanh tien: " << tinhThanhTien() << endl;
}

double GiaoDichVang::tinhThanhTien() {
    return soLuong * donGia;
}

void GiaoDichTienTe::nhap() {
    GiaoDich::nhap();
    cout << "Loai tien (VND/USD/EURO): "; cin >> loaiTien;
    cout << "Ti gia: "; cin >> tiGia;
}

void GiaoDichTienTe::xuat() {
    GiaoDich::xuat();
    cout << ", Loai tien: " << loaiTien
         << ", Ti gia: " << tiGia
         << ", Thanh tien: " << tinhThanhTien() << endl;
}

double GiaoDichTienTe::tinhThanhTien() {
    if (loaiTien == "VND") return soLuong * donGia;
    return soLuong * donGia * tiGia;
}

string GiaoDichTienTe::getLoaiTien() {
    return loaiTien;
}

void QuanLyGiaoDich::nhapDanhSachVang() {
    int n;
    cout << "Nhap so giao dich vang: "; cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Nhap GD vang thu " << i + 1 << ":" << endl;
        GiaoDichVang gd;
        gd.nhap();
        dsVang.push_back(gd);
    }
}

void QuanLyGiaoDich::nhapDanhSachTienTe() {
    int n;
    cout << "Nhap so giao dich tien te: "; cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Nhap GD tien te thu " << i + 1 << ":" << endl;
        GiaoDichTienTe gd;
        gd.nhap();
        dsTienTe.push_back(gd);
    }
}

void QuanLyGiaoDich::xuatGiaoDichVangMax() {
    double maxTT = 0;
    for (int i = 0; i < (int)dsVang.size(); ++i)
        if (dsVang[i].tinhThanhTien() > maxTT)
            maxTT = dsVang[i].tinhThanhTien();

    cout << endl << "Giao dich vang co thanh tien cao nhat:" << endl;
    for (int i = 0; i < (int)dsVang.size(); ++i)
        if (dsVang[i].tinhThanhTien() == maxTT)
            dsVang[i].xuat();
}

void QuanLyGiaoDich::xuatGiaoDichEuroMin() {
    double minTT = 1e18;
    for (int i = 0; i < (int)dsTienTe.size(); ++i)
        if (dsTienTe[i].getLoaiTien() == "EURO")
            if (dsTienTe[i].tinhThanhTien() < minTT)
                minTT = dsTienTe[i].tinhThanhTien();

    cout << endl << "Giao dich tien te EURO co thanh tien thap nhat:" << endl;
    for (int i = 0; i < (int)dsTienTe.size(); ++i)
        if (dsTienTe[i].getLoaiTien() == "EURO" && dsTienTe[i].tinhThanhTien() == minTT)
            dsTienTe[i].xuat();
}

void QuanLyGiaoDich::xuatGiaoDichTren1Ty() {
    cout << endl << "Cac giao dich co thanh tien tren 1 ty:" << endl;
    for (int i = 0; i < (int)dsVang.size(); ++i)
        if (dsVang[i].tinhThanhTien() > 1000000000)
            dsVang[i].xuat();

    for (int i = 0; i < (int)dsTienTe.size(); ++i)
        if (dsTienTe[i].tinhThanhTien() > 1000000000)
            dsTienTe[i].xuat();
}

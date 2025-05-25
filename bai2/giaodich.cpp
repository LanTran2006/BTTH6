#include "giaodich.h"

void GiaoDich::nhap() {
    cout << "Nhap ma giao dich, ngay, don gia, dien tich: ";
    cin >> maGD >> ngay >> donGia >> dienTich;
}

void GiaoDich::xuat() {
    cout << maGD << " " << ngay << " " << fixed << setprecision(2) << donGia << " " << dienTich;
}

string GiaoDich::getNgay() {
    return ngay;
}

double GiaoDich::thanhTien() {
    return 0;
}

void GiaoDichDat::nhap() {
    GiaoDich::nhap();
    cout << "Nhap loai dat (A/B/C): ";
    cin >> loaiDat;
}

double GiaoDichDat::thanhTien() {
    return (loaiDat == 'A') ? dienTich * donGia * 1.5 : dienTich * donGia;
}

void GiaoDichDat::xuat() {
    GiaoDich::xuat();
    cout << " " << loaiDat << " " << fixed << setprecision(2) << thanhTien() << endl;
}

void GiaoDichNhaPho::nhap() {
    GiaoDich::nhap();
    cout << "Nhap loai nha (cao_cap / thuong): ";
    cin >> loaiNha;
    cin.ignore();
    cout << "Nhap dia chi: ";
    getline(cin, diaChi);
}

double GiaoDichNhaPho::thanhTien() {
    return (loaiNha == "cao_cap") ? dienTich * donGia : dienTich * donGia * 0.9;
}

void GiaoDichNhaPho::xuat() {
    GiaoDich::xuat();
    cout << " " << loaiNha << " " << diaChi << " " << fixed << setprecision(2) << thanhTien() << endl;
}

void GiaoDichCanHo::nhap() {
    GiaoDich::nhap();
    cout << "Nhap ma can ho va vi tri tang: ";
    cin >> maCan >> viTriTang;
}

double GiaoDichCanHo::thanhTien() {
    if (viTriTang == 1) return dienTich * donGia * 2;
    else if (viTriTang >= 15) return dienTich * donGia * 1.2;
    else return dienTich * donGia;
}

void GiaoDichCanHo::xuat() {
    GiaoDich::xuat();
    cout << " " << maCan << " " << viTriTang << " " << fixed << setprecision(2) << thanhTien() << endl;
}

bool laThang12Nam2024(string ngay) {
    return ngay.substr(3, 2) == "12" && ngay.substr(6) == "2024";
}

void QuanLyGiaoDich::nhapGiaoDich() {
    int n1, n2, n3;
    cout << "Nhap so luong giao dich dat: ";
    cin >> n1;
    dsDat.resize(n1);
    for (auto& g : dsDat) g.nhap();

    cout << "Nhap so luong giao dich nha pho: ";
    cin >> n2;
    dsNha.resize(n2);
    for (auto& g : dsNha) g.nhap();

    cout << "Nhap so luong giao dich can ho: ";
    cin >> n3;
    dsCan.resize(n3);
    for (auto& g : dsCan) g.nhap();
}

void QuanLyGiaoDich::xuatThongKeSoLuong() {
    cout << endl;
    cout << "Tong so giao dich Dat: " << dsDat.size() << endl;
    cout << "Tong so giao dich Nha pho: " << dsNha.size() << endl;
    cout << "Tong so giao dich Can ho: " << dsCan.size() << endl;
}

void QuanLyGiaoDich::xuatTrungBinhCanHo() {
    if (dsCan.empty()) return;
    double tong = 0;
    for (auto& g : dsCan) tong += g.thanhTien();
    cout << "Trung binh thanh tien Can ho: " << fixed << setprecision(2) << tong / dsCan.size() << endl;
}

void QuanLyGiaoDich::xuatNhaPhoMax() {
    double maxVal = 0;
    for (auto& g : dsNha) maxVal = max(maxVal, g.thanhTien());
    cout << endl << "Giao dich Nha pho co thanh tien cao nhat:" << endl;
    for (auto& g : dsNha) if (g.thanhTien() == maxVal) g.xuat();
}

void QuanLyGiaoDich::xuatThang12Nam2024() {
    cout << endl << "Giao dich trong thang 12 nam 2024:" << endl;
    for (auto& g : dsDat) if (laThang12Nam2024(g.getNgay())) g.xuat();
    for (auto& g : dsNha) if (laThang12Nam2024(g.getNgay())) g.xuat();
    for (auto& g : dsCan) if (laThang12Nam2024(g.getNgay())) g.xuat();
}

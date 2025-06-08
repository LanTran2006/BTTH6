#include "khachhang.h"

// ---------------- KhachHang ----------------
void KhachHang::nhap(ifstream &in) {
    in >> ten >> soLuong >> donGia;
}

void KhachHang::xuat(ofstream &out) {
    out << ten << "\n" << fixed << setprecision(2) << tinhTien() << "\n";
}

// ---------------- KhachHangA ----------------
double KhachHangA::tinhTien() {
    double tien = soLuong * donGia;
    return tien + tien * 0.10;
}

// ---------------- KhachHangB ----------------
void KhachHangB::nhap(ifstream &in) {
    KhachHang::nhap(in);
    in >> soNam;
}

double KhachHangB::tinhTien() {
    double tien = soLuong * donGia;
    double giam = min(soNam * 0.05, 0.5);
    tien = tien * (1 - giam);
    return tien + tien * 0.10;
}

// ---------------- KhachHangC ----------------
double KhachHangC::tinhTien() {
    double tien = soLuong * donGia * 0.5;
    return tien + tien * 0.10;
}

// ---------------- CongTy ----------------
void CongTy::docFile(string tenFile) {
    ifstream in(tenFile);
    in >> x >> y >> z;

    for (int i = 0; i < x; i++) {
        KhachHang *kh = new KhachHangA();
        kh->nhap(in);
        danhSach.push_back(kh);
    }
    for (int i = 0; i < y; i++) {
        KhachHang *kh = new KhachHangB();
        kh->nhap(in);
        danhSach.push_back(kh);
    }
    for (int i = 0; i < z; i++) {
        KhachHang *kh = new KhachHangC();
        kh->nhap(in);
        danhSach.push_back(kh);
    }

    in.close();
}

void CongTy::ghiFile(string tenFile) {
    ofstream out(tenFile);
    double tong = 0;

    for (int i = 0; i < danhSach.size(); i++) {
        danhSach[i]->xuat(out);
        tong += danhSach[i]->tinhTien();
    }

    out << fixed << setprecision(2);
    out << "TongTienThuDuoc: " << tong << "\n";

    out.close();
}

CongTy::~CongTy() {
    for (int i = 0; i < danhSach.size(); i++) {
        delete danhSach[i];
    }
}

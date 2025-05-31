#include "congty.h"

void NhanVien::nhap() {
    cout << "Ma NV: "; getline(cin, maNV);
    cout << "Ho ten: "; getline(cin, hoTen);
    cout << "Tuoi: "; cin >> tuoi; cin.ignore();
    cout << "SDT: "; getline(cin, sdt);
    cout << "Email: "; getline(cin, email);
    cout << "Luong co ban: "; cin >> luongCoBan; cin.ignore();
}

void NhanVien::xuat() {
    cout << "Ma NV: " << maNV << ", Ho ten: " << hoTen
         << ", Tuoi: " << tuoi << ", SDT: " << sdt
         << ", Email: " << email << ", Luong co ban: " << luongCoBan;
}

void LapTrinhVien::nhap() {
    NhanVien::nhap();
    cout << "So gio OT: "; cin >> soGioOT; cin.ignore();
}

void LapTrinhVien::xuat() {
    NhanVien::xuat();
    cout << ", So gio OT: " << soGioOT
         << ", Luong: " << tinhLuong() << endl;
}

double LapTrinhVien::tinhLuong() {
    return luongCoBan + soGioOT * 200000;
}

bool LapTrinhVien::laLapTrinhVien() {
    return true;
}

void KiemChungVien::nhap() {
    NhanVien::nhap();
    cout << "So loi phat hien: "; cin >> soLoiPhatHien; cin.ignore();
}

void KiemChungVien::xuat() {
    NhanVien::xuat();
    cout << ", So loi phat hien: " << soLoiPhatHien
         << ", Luong: " << tinhLuong() << endl;
}

double KiemChungVien::tinhLuong() {
    return luongCoBan + soLoiPhatHien * 50000;
}

bool KiemChungVien::laLapTrinhVien() {
    return false;
}

void CongTy::nhapDanhSach() {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int loai;
        cout << "1. Lap trinh vien\n2. Kiem chung vien\nChon loai: ";
        cin >> loai; cin.ignore();
        NhanVien* nv;
        if (loai == 1) nv = new LapTrinhVien();
        else nv = new KiemChungVien();
        nv->nhap();
        danhSach.push_back(nv);
    }
}

void CongTy::xuatDanhSach() {
    cout << "\n--- Danh sach nhan vien ---\n";
    for (auto nv : danhSach) nv->xuat();
}

void CongTy::xuatLuongThapHonTB() {
    double tong = 0;
    for (auto nv : danhSach) tong += nv->tinhLuong();
    double tb = tong / danhSach.size();
    cout << "\n--- Nhan vien co luong thap hon TB (" << tb << ") ---\n";
    for (auto nv : danhSach)
        if (nv->tinhLuong() < tb) nv->xuat();
}

void CongTy::xuatLuongCaoNhat() {
    NhanVien* maxNV = danhSach[0];
    for (auto nv : danhSach)
        if (nv->tinhLuong() > maxNV->tinhLuong()) maxNV = nv;
    cout << "\n--- Nhan vien co luong cao nhat ---\n";
    maxNV->xuat();
}

void CongTy::xuatLuongThapNhat() {
    NhanVien* minNV = danhSach[0];
    for (auto nv : danhSach)
        if (nv->tinhLuong() < minNV->tinhLuong()) minNV = nv;
    cout << "\n--- Nhan vien co luong thap nhat ---\n";
    minNV->xuat();
}

void CongTy::xuatLapTrinhLuongCaoNhat() {
    NhanVien* maxLTV = nullptr;
    for (auto nv : danhSach)
        if (nv->laLapTrinhVien()) {
            if (!maxLTV || nv->tinhLuong() > maxLTV->tinhLuong())
                maxLTV = nv;
        }
    cout << "\n--- Lap trinh vien co luong cao nhat ---\n";
    if (maxLTV) maxLTV->xuat();
}

void CongTy::xuatKiemChungLuongThapNhat() {
    NhanVien* minKCV = nullptr;
    for (auto nv : danhSach)
        if (!nv->laLapTrinhVien()) {
            if (!minKCV || nv->tinhLuong() < minKCV->tinhLuong())
                minKCV = nv;
        }
    cout << "\n--- Kiem chung vien co luong thap nhat ---\n";
    if (minKCV) minKCV->xuat();
}

CongTy::~CongTy() {
    for (auto nv : danhSach) delete nv;
}

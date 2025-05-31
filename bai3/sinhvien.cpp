#include "sinhvien.h"

void SinhVien::nhap() {
    cout << "Nhap ma sinh vien: ";
    cin >> maSV;
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap dia chi: ";
    getline(cin, diaChi);
    cout << "Nhap tong so tin chi: ";
    cin >> tongTinChi;
    cout << "Nhap diem trung binh: ";
    cin >> diemTB;
}

void SinhVien::xuat() {
    cout << "Ma SV: " << maSV << ", Ho ten: " << hoTen
         << ", Dia chi: " << diaChi << ", Tong TC: " << tongTinChi
         << ", Diem TB: " << diemTB;
}

float SinhVien::getDiemTB() {
    return diemTB;
}

// ---------------- Cao dang ----------------
void SinhVienCaoDang::nhap() {
    SinhVien::nhap();
    cout << "Nhap diem thi tot nghiep: ";
    cin >> diemTN;
}

void SinhVienCaoDang::xuat() {
    SinhVien::xuat();
    cout << ", Diem TN: " << diemTN << ", He: Cao dang\n";
}

bool SinhVienCaoDang::totNghiep() {
    return tongTinChi >= 120 && diemTB >= 5 && diemTN >= 5;
}

string SinhVienCaoDang::loai() {
    return "CD";
}

// ---------------- Dai hoc ----------------
void SinhVienDaiHoc::nhap() {
    SinhVien::nhap();
    cin.ignore();
    cout << "Nhap ten luan van: ";
    getline(cin, tenLuanVan);
    cout << "Nhap diem luan van: ";
    cin >> diemLuanVan;
}

void SinhVienDaiHoc::xuat() {
    SinhVien::xuat();
    cout << ", Ten luan van: " << tenLuanVan << ", Diem luan van: "
         << diemLuanVan << ", He: Dai hoc\n";
}

bool SinhVienDaiHoc::totNghiep() {
    return tongTinChi >= 170 && diemTB >= 5 && diemLuanVan >= 5;
}

string SinhVienDaiHoc::loai() {
    return "DH";
}

// ---------------- Quan ly sinh vien ----------------
QuanLySinhVien::~QuanLySinhVien() {
    for (auto sv : ds) delete sv;
}

void QuanLySinhVien::nhapDanhSach() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int loai;
        cout << "\n1. Cao dang | 2. Dai hoc\nChon loai sinh vien: ";
        cin >> loai;
        SinhVien* sv;
        if (loai == 1) sv = new SinhVienCaoDang();
        else sv = new SinhVienDaiHoc();
        sv->nhap();
        ds.push_back(sv);
    }
}

void QuanLySinhVien::xuatDanhSach() {
    cout << "\n=== Danh sach sinh vien ===\n";
    for (auto sv : ds) sv->xuat();
}

void QuanLySinhVien::xuatTotNghiep() {
    cout << "\n=== Sinh vien tot nghiep ===\n";
    for (auto sv : ds)
        if (sv->totNghiep()) sv->xuat();
}

void QuanLySinhVien::xuatKhongTotNghiep() {
    cout << "\n=== Sinh vien KHONG tot nghiep ===\n";
    for (auto sv : ds)
        if (!sv->totNghiep()) sv->xuat();
}

void QuanLySinhVien::sinhVienDiemTBCaoNhat() {
    double maxDH = -1, maxCD = -1;
    SinhVien* svDH = nullptr;
    SinhVien* svCD = nullptr;

    for (auto sv : ds) {
        if (sv->loai() == "DH" && sv->getDiemTB() > maxDH) {
            maxDH = sv->getDiemTB();
            svDH = sv;
        }
        if (sv->loai() == "CD" && sv->getDiemTB() > maxCD) {
            maxCD = sv->getDiemTB();
            svCD = sv;
        }
    }

    cout << "\n=== SV dai hoc co diem TB cao nhat ===\n";
    if (svDH) svDH->xuat();

    cout << "\n=== SV cao dang co diem TB cao nhat ===\n";
    if (svCD) svCD->xuat();
}

void QuanLySinhVien::thongKeKhongTotNghiep() {
    int cd = 0, dh = 0;
    for (auto sv : ds) {
        if (!sv->totNghiep()) {
            if (sv->loai() == "CD") cd++;
            else dh++;
        }
    }

    cout << "\nSo SV cao dang KHONG tot nghiep: " << cd;
    cout << "\nSo SV dai hoc KHONG tot nghiep: " << dh;
}

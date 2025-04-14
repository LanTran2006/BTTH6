#include "bai7.h"
#include <sstream>

NhanVienVP::NhanVienVP() {
    maNV = "";
    hoTen = "";
    ngaySinh = "";
    luong = 0;
}

NhanVienVP::NhanVienVP(string maNV, string hoTen, string ngaySinh, double luong) {
    this->maNV = maNV;
    this->hoTen = hoTen;
    this->ngaySinh = ngaySinh;
    this->luong = luong;
}

void NhanVienVP::nhap() {
    cout << "Nhap ma NV: ";
    cin >> maNV;
    cin.ignore();

    cout << "Nhap ho ten: ";
    getline(cin, hoTen);

    cout << "Nhap ngay sinh (dd mm yyyy): ";
    getline(cin, ngaySinh);

    cout << "Nhap luong: ";
    cin >> luong;
}

void NhanVienVP::xuat() const {
    cout << left << setw(10) << maNV
         << setw(20) << hoTen
         << setw(15) << ngaySinh
         << setw(10) << luong << endl;
}

double NhanVienVP::getLuong() const {
    return luong;
}

string NhanVienVP::getNgaySinh() const {
    return ngaySinh;
}

void NhanVienVP::nhapDanhSach(vector<NhanVienVP>& danhSach) {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    danhSach.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin nhan vien " << i + 1 << ":\n";
        danhSach[i].nhap();
    }
}

void NhanVienVP::xuatDanhSach(const vector<NhanVienVP>& danhSach) {
    cout << "\nDanh sach nhan vien:\n";
    for (int i = 0; i < danhSach.size(); i++) {
        danhSach[i].xuat();
    }
}

NhanVienVP NhanVienVP::timNhanVienLuongCaoNhat(const vector<NhanVienVP>& danhSach) {
    if (!danhSach.size()) return NhanVienVP();

    NhanVienVP maxNV = danhSach[0];
    for (int i = 1; i < danhSach.size(); i++) {
        if (danhSach[i].getLuong() > maxNV.getLuong()) {
            maxNV = danhSach[i];
        }
    }
    return maxNV;
}

double NhanVienVP::tinhTongLuong(const vector<NhanVienVP>& danhSach) {
    double tong = 0;
    for (int i = 0; i < danhSach.size(); i++) {
        tong += danhSach[i].getLuong();
    }
    return tong;
}

// Hàm tách chuỗi ngày tháng năm
void tachNgayThangNam(const string& ngaySinh, int& ngay, int& thang, int& nam) {
    stringstream ss(ngaySinh);
    ss >> ngay >> thang >> nam;
}

NhanVienVP NhanVienVP::timNhanVienTuoiCaoNhat(const vector<NhanVienVP>& danhSach) {
    if (!danhSach.size()) return NhanVienVP();

    NhanVienVP oldest = danhSach[0];
    int d1, m1, y1;
    tachNgayThangNam(oldest.getNgaySinh(), d1, m1, y1);

    for (int i = 1; i < danhSach.size(); i++) {
        int d2, m2, y2;
        tachNgayThangNam(danhSach[i].getNgaySinh(), d2, m2, y2);

        if (y2 < y1 || (y2 == y1 && m2 < m1) || (y2 == y1 && m2 == m1 && d2 < d1)) {
            oldest = danhSach[i];
            d1 = d2; m1 = m2; y1 = y2;
        }
    }
    return oldest;
}

void NhanVienVP::sapXepLuongTangDan(vector<NhanVienVP>& danhSach) {
    int n = danhSach.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (danhSach[j].getLuong() > danhSach[j + 1].getLuong()) {
                NhanVienVP temp = danhSach[j];
                danhSach[j] = danhSach[j + 1];
                danhSach[j + 1] = temp;
            }
        }
    }
}

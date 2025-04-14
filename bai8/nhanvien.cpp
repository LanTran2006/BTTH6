#include "nhanvien.h"
void Date::nhap() {
   cin >> ngay;
   cin >> thang;
    cin >> nam;
}

void Date::xuat() const {
    cout << ngay << "/" << thang << "/" << nam;
}

int Date::tinhTuoi() const {
    return 2025 - nam;
}

bool Date::treHon(const Date& other) const {
    if (nam != other.nam) return nam < other.nam;
    if (thang != other.thang) return thang < other.thang;
    return ngay < other.ngay;
}

void cNhanVienSX::nhap() {
    cout << "Nhap ma NV: "; cin >> maNV;
    cin.ignore();
    cout << "Nhap ho ten: "; getline(cin, hoTen);
    cout << "Nhap ngay sinh:\n"; ngaySinh.nhap();
    cout << "Nhap so san pham: "; cin >> soSP;
    cout << "Nhap don gia: "; cin >> donGia;
}

void cNhanVienSX::xuat() const {
    cout << "Ma NV: " << maNV << ", Ho ten: " << hoTen << ", Ngay sinh: ";
    ngaySinh.xuat();
    cout << ", So SP: " << soSP << ", Don gia: " << donGia;
    cout << ", Luong: " << tinhLuong() << ", Tuoi: " << getTuoi() << endl;
}

float cNhanVienSX::tinhLuong() const {
    return soSP * donGia;
}

int cNhanVienSX::getTuoi() const {
    return ngaySinh.tinhTuoi();
}



cNhanVienSX cNhanVienSX::timLuongThapNhat(const vector<cNhanVienSX>& ds) {
    return *min_element(ds.begin(), ds.end(), [](const cNhanVienSX& a, const cNhanVienSX& b) {
        return a.tinhLuong() < b.tinhLuong();
    });
}

float cNhanVienSX::tongLuong(const vector<cNhanVienSX>& ds) {
    float tong = 0;
    for (const auto& nv : ds) tong += nv.tinhLuong();
    return tong;
}
bool cNhanVienSX::treHonNguoiKhac(const cNhanVienSX& other) const {
    return ngaySinh.treHon(other.ngaySinh);
}
cNhanVienSX cNhanVienSX::timNguoiGiaNhat(const vector<cNhanVienSX>& ds) {
    return *min_element(ds.begin(), ds.end(), [](const cNhanVienSX& a, const cNhanVienSX& b) {
        return a.treHonNguoiKhac(b);
    });
}

void cNhanVienSX::sapXepTheoLuong(vector<cNhanVienSX>& ds) {
    sort(ds.begin(), ds.end(), [](const cNhanVienSX& a, const cNhanVienSX& b) {
        return a.tinhLuong() < b.tinhLuong();
    });
}

void cNhanVienSX::xuatDanhSach(const vector<cNhanVienSX>& ds) {
    for (const auto& nv : ds) nv.xuat();
}
void cNhanVienSX::nhapDanhSach(vector<cNhanVienSX>& ds) {
    int n;
    cout << "Nhap so nhan vien: "; cin >> n;
    ds.resize(n);
    for (int i = 0; i < n; ++i) {
        cout << "\nNhap nhan vien thu " << i + 1 << ":\n";
        ds[i].nhap();
    }
}
void cNhanVienSX::xuLyDanhSach(vector<cNhanVienSX>& ds) {
    cout << "\n--- Danh sach nhan vien ---\n";
    xuatDanhSach(ds);

    cout << "\nNhan vien co luong thap nhat:\n";
    timLuongThapNhat(ds).xuat();

    cout << "\nTong luong cong ty phai tra: " << tongLuong(ds) << endl;

    cout << "\nNhan vien co tuoi cao nhat:\n";
    timNguoiGiaNhat(ds).xuat();

    sapXepTheoLuong(ds);
    cout << "\n--- Danh sach sap xep theo luong tang dan ---\n";
    xuatDanhSach(ds);
}

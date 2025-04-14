#include "bai6.h"

// Constructor của cCandidate
cCandidate::cCandidate(string m, string t, string ns, double to, double v, double a)
    : ma(m), ten(t), ngaySinh(ns), toan(to), van(v), anh(a) {}

// Tính tổng điểm
double cCandidate::tongDiem() const {
    return toan + van + anh;
}

// Xuất thông tin thí sinh
void cCandidate::xuat() const {
    cout << "Ma: " << ma << ", Ten: " << ten << ", Ngay sinh: " << ngaySinh
         << ", Toan: " << toan << ", Van: " << van << ", Anh: " << anh
         << ", Tong diem: " << tongDiem() << endl;
}

// Nhập danh sách thí sinh
void cListCandidate::nhapDanhSach(int n) {
    for (int i = 0; i < n; i++) {
        string ma, ten, ngaySinh;
        double toan, van, anh;

        cout << "Nhap ma: ";
        cin >> ma;
        cin.ignore();

        cout << "Nhap ten: ";
        getline(cin, ten);

        cout << "Nhap ngay sinh: ";
        getline(cin, ngaySinh);

        cout << "Nhap diem Toan, Van, Anh: ";
        cin >> toan >> van >> anh;

        danhSach.push_back(cCandidate(ma, ten, ngaySinh, toan, van, anh));
    }
}


// Xuất danh sách thí sinh có tổng điểm > 15
void cListCandidate::xuatDanhSachLonHon15() const {
    cout << "Thi sinh co tong diem > 15:\n";
    for (size_t i = 0; i < danhSach.size(); i++) {
        if (danhSach[i].tongDiem() > 15) {
            danhSach[i].xuat();
        }
    }
}

// Tìm thí sinh có tổng điểm cao nhất
void cListCandidate::thiSinhDiemCaoNhat() const {
    if (!danhSach.size()) return;

    const cCandidate* maxThiSinh = &danhSach[0];
    for (int i = 1; i < danhSach.size(); i++) {
        if (danhSach[i].tongDiem() > maxThiSinh->tongDiem()) {
            maxThiSinh = &danhSach[i];
        }
    }
    cout << "Thi sinh co tong diem cao nhat:\n";
    maxThiSinh->xuat();
}

// Sắp xếp danh sách theo tổng điểm giảm dần (Bubble Sort)
void cListCandidate::sapXepGiamDan() {
    for (int i = 0; i < danhSach.size() - 1; i++) {
        for (int j = 0; j < danhSach.size() - i - 1; j++) {
            if (danhSach[j].tongDiem() < danhSach[j + 1].tongDiem()) {
                swap(danhSach[j], danhSach[j + 1]);
            }
        }
    }
}

// Xuất danh sách thí sinh
void cListCandidate::xuatDanhSach() const {
    cout << "Danh sach thi sinh:\n";
    for (int i = 0; i < danhSach.size(); i++) {
        danhSach[i].xuat();
    }
}

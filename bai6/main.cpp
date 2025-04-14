#include "bai6.h"

int main() {
    cListCandidate danhSach;
    int n;

    cout << "Nhap so luong thi sinh: ";
    cin >> n;
    danhSach.nhapDanhSach(n);

    danhSach.xuatDanhSach();

    danhSach.xuatDanhSachLonHon15();

    danhSach.thiSinhDiemCaoNhat();

    danhSach.sapXepGiamDan();
    cout << "Danh sach sau khi sap xep giam dan theo tong diem:\n";
    danhSach.xuatDanhSach();

    return 0;
}

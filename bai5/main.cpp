#include "dathuc.h"

int main() {
    DaThuc dt1, dt2;
    cout << "Nhap da thuc thu nhat:\n";
    dt1.nhap();
    cout << "Nhap da thuc thu hai:\n";
    dt2.nhap();

    cout << "\nDa thuc 1: ";
    dt1.xuat();
    cout << "Da thuc 2: ";
    dt2.xuat();

    DaThuc tong = dt1.cong(dt2);
    cout << "\nTong hai da thuc: ";
    tong.xuat();

    DaThuc hieu = dt1.tru(dt2);
    cout << "Hieu hai da thuc: ";
    hieu.xuat();

    double x;
    cout << "\nNhap gia tri x de tinh gia tri cua da thuc 1: ";
    cin >> x;
    cout << "Gia tri da thuc 1 tai x = " << x << " la: " << dt1.tinhGiaTri(x) << endl;

    return 0;
}

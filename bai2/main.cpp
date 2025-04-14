#include "DaGiac.h"

int main() {
    DaGiac polygon;
    polygon.Nhap();

    cout << "\nThong tin da giac vua nhap:\n";
    polygon.Xuat();

    polygon.tinhTien(2, 3);
    cout << "\nSau khi tinh tien (2,3):\n";
    polygon.Xuat();

    polygon.phongTo(2);
    cout << "\nSau khi phong to ty le 2:\n";
    polygon.Xuat();

    polygon.quay(45);
    cout << "\nSau khi quay 45 do:\n";
    polygon.Xuat();

    return 0;
}

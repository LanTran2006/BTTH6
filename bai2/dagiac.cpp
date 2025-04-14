#include "dagiac.h"

Diem::Diem(double x, double y) : x(x), y(y) {}
Diem::~Diem() {
   return;
}

void Diem::setXY(double xVal, double yVal) {
    x = xVal;
    y = yVal;
}


double Diem::getX() const { return x; }
double Diem::getY() const { return y; }

void Diem::Xuat() const {
    cout << "(" << x << ", " << y << ")";
}

void Diem::tinhTien(double dx, double dy) {
    x += dx;
    y += dy;
}
double Diem::tinhKhoangCach(const Diem d) {
    return sqrt(pow(x - d.x, 2) + pow(y - d.y,2));
}

void Diem::phongTo(double scale) {
    x *= scale;
    y *= scale;
}

void Diem::quay(double alpha) {
    double rad = alpha * M_PI / 180.0;
    double xNew = x * cos(rad) - y * sin(rad);
    double yNew = x * sin(rad) + y * cos(rad);
    x = xNew;
    y = yNew;
}

DaGiac::DaGiac() : n(0) {}

DaGiac::DaGiac(const DaGiac& fi) : n(fi.n), dg(fi.dg) {}

DaGiac::DaGiac(int num, vector<Diem> points) : n(num), dg(points) {}

DaGiac::~DaGiac() {}

void DaGiac::Nhap() {
    cout << "Nhap so dinh: ";
    cin >> n;
    dg.resize(n);
    for (int i = 0; i < n; ++i) {
        double x, y;
        cout << "Nhap diem thu " << i + 1 << " (x y): ";
        cin >> x >> y;
        dg[i].setXY(x, y);
    }
}

void DaGiac::Xuat() {
    cout << "Da giac gom " << n << " dinh:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Dinh " << i + 1 << ": ";
        dg[i].Xuat();
        cout << endl;
    }
}

void DaGiac::tinhTien(double dx, double dy) {
    for (int i = 0; i < n; ++i) {
        dg[i].tinhTien(dx, dy);
    }
}

void DaGiac::phongTo(double scale) {
    for (int i = 0; i < n; ++i) {
        dg[i].phongTo(scale);
    }
}

void DaGiac::quay(double alpha) {
    for (int i = 0; i < n; ++i) {
        dg[i].quay(alpha);
    }
}

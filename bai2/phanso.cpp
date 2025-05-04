#include "phanSo.h"

PhanSo::PhanSo(int t, int m) {
    if (m == 0) {
        cout << "Mau so khong duoc bang 0!" << endl;
        exit(1);
    }
    tu = t;
    mau = m;
    rutGon();
}

PhanSo::PhanSo(int nguyen) {
    tu = nguyen;
    mau = 1;
}

void PhanSo::rutGon() {
    int gcd = __gcd(abs(tu), abs(mau));
    tu /= gcd;
    mau /= gcd;
    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }
}

PhanSo PhanSo::operator+(PhanSo& ps) {
    return PhanSo(tu * ps.mau + mau * ps.tu, mau * ps.mau);
}

PhanSo PhanSo::operator-(PhanSo& ps) {
    return PhanSo(tu * ps.mau - mau * ps.tu, mau * ps.mau);
}

PhanSo PhanSo::operator*(PhanSo& ps) {
    return PhanSo(tu * ps.tu, mau * ps.mau);
}

PhanSo PhanSo::operator/(PhanSo& ps) {
    if (ps.tu == 0) {
        cout<< "Loi: chia cho 0!" << endl;
        exit(1);
    }
    return PhanSo(tu * ps.mau, mau * ps.tu);
}

bool PhanSo::operator==(PhanSo& ps) {
    ps.rutGon();
    rutGon();
    return tu == ps.tu && mau == ps.mau;
}

bool PhanSo::operator!=(PhanSo& ps) {
    return !(*this == ps);
}

bool PhanSo::operator<(PhanSo& ps) {
    return tu * ps.mau < ps.tu * mau;
}

bool PhanSo::operator>(PhanSo& ps) {
    return tu * ps.mau > ps.tu * mau;
}

istream& operator>>(istream& is, PhanSo& ps) {
    cout << "Nhap tu so: ";
    is >> ps.tu;
    cout << "Nhap mau so: ";
    is >> ps.mau;
    if (ps.mau == 0) {
        cout << "Mau so khong duoc bang 0!" << endl;
        exit(1);
    }
    ps.rutGon();
    return is;
}

ostream& operator<<(ostream& os, PhanSo& ps) {
    if (ps.mau == 1)
        os << ps.tu;
    else
        os << ps.tu << "/" << ps.mau;
    return os;
}

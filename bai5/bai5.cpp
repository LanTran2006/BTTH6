#include "dathuc.h"

DaThuc::DaThuc() : bac(0) {
    hs.push_back(0);
}

DaThuc::DaThuc(int bac) : bac(bac) {
    hs.resize(bac + 1, 0);
}

void DaThuc::nhap() {
    cout << "Nhap bac cua da thuc: ";
    cin >> bac;
    hs.resize(bac + 1);
    for (int i = bac; i >= 0; --i) {
        cout << "He so bac " << i << ": ";
        cin >> hs[i];
    }
}

void DaThuc::xuat() const {
    for (int i = bac; i >= 0; --i) {
        cout << hs[i];
        if (i > 0) cout << "x^" << i << " + ";
    }
    cout << endl;
}

double DaThuc::tinhGiaTri(double x) const {
    double result = 0;
    for (int i = 0; i <= bac; ++i) {
        result += hs[i] * pow(x, i);
    }
    return result;
}

DaThuc DaThuc::cong(const DaThuc& other) const {
    int maxBac = max(bac, other.bac);
    DaThuc result(maxBac);
    for (int i = 0; i <= maxBac; ++i) {
        double a = (i <= bac) ? hs[i] : 0;
        double b = (i <= other.bac) ? other.hs[i] : 0;
        result.hs[i] = a + b;
    }
    return result;
}

DaThuc DaThuc::tru(const DaThuc& other) const {
    int maxBac = max(bac, other.bac);
    DaThuc result(maxBac);
    for (int i = 0; i <= maxBac; ++i) {
        double a = (i <= bac) ? hs[i] : 0;
        double b = (i <= other.bac) ? other.hs[i] : 0;
        result.hs[i] = a - b;
    }
    return result;
}

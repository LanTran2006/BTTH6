#include "sophuc.h"

SoPhuc::SoPhuc(double thuc, double ao) {
    this->thuc = thuc;
    this->ao = ao;
}

SoPhuc::SoPhuc(double thuc) {
    this->thuc = thuc;
    this->ao = 0;
}

SoPhuc SoPhuc::operator+(SoPhuc sp) {
    return SoPhuc(thuc + sp.thuc, ao + sp.ao);
}

SoPhuc SoPhuc::operator-(SoPhuc sp) {
    return SoPhuc(thuc - sp.thuc, ao - sp.ao);
}

SoPhuc SoPhuc::operator*(SoPhuc sp) {
    double real = thuc * sp.thuc - ao * sp.ao;
    double imag = thuc * sp.ao + ao * sp.thuc;
    return SoPhuc(real, imag);
}

SoPhuc SoPhuc::operator/(SoPhuc sp) {
    double mau = sp.thuc * sp.thuc + sp.ao * sp.ao;
    double real = (thuc * sp.thuc + ao * sp.ao) / mau;
    double imag = (ao * sp.thuc - thuc * sp.ao) / mau;
    return SoPhuc(real, imag);
}

bool SoPhuc::operator==(SoPhuc sp) {
    return thuc == sp.thuc && ao == sp.ao;
}

bool SoPhuc::operator!=(SoPhuc sp) {
    return !(*this == sp);
}

ostream& operator<<(ostream& os, SoPhuc sp) {
    os << sp.thuc;
    if (sp.ao >= 0)
        os << " + " << sp.ao << "i";
    else
        os << " - " << -sp.ao << "i";
    return os;
}

istream& operator>>(istream& is, SoPhuc& sp) {
    cout << "Nhap phan thuc: ";
    is >> sp.thuc;
    cout << "Nhap phan ao: ";
    is >> sp.ao;
    return is;
}

#ifndef DATHUC_H_INCLUDED
#define DATHUC_H_INCLUDED

#include <bits/stdc++.h>
using namespace std;

class DaThuc {
private:
    int bac;
    vector<double> hs;

public:
    DaThuc();
    DaThuc(int bac);

    void nhap();
    void xuat() const;
    double tinhGiaTri(double x) const;

    DaThuc cong(const DaThuc& other) const;
    DaThuc tru(const DaThuc& other) const;
};



#endif


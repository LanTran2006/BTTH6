#ifndef PHANSO_H_INCLUDED
#define PHANSO_H_INCLUDED

#include<bits/stdc++.h>
using namespace std;

class PhanSo {
private:
    int tu;
    int mau;
    void rutGon();

public:
    PhanSo(int t = 0, int m = 1);
    PhanSo(int nguyen);

    PhanSo operator+(PhanSo& ps);
    PhanSo operator-(PhanSo& ps);
    PhanSo operator*(PhanSo& ps);
    PhanSo operator/(PhanSo& ps);

    bool operator==(PhanSo& ps);
    bool operator!=(PhanSo& ps);
    bool operator<(PhanSo& ps);
    bool operator>(PhanSo& ps);

    friend istream& operator>>(istream& is, PhanSo& ps);
    friend ostream& operator<<(ostream& os, PhanSo& ps);
};

#endif // PHANSO_H_INCLUDED

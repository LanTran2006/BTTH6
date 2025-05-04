#ifndef SOPHUC_H_INCLUDED
#define SOPHUC_H_INCLUDED

#include <bits/stdc++.h>
using namespace std;

class SoPhuc {
private:
    double thuc;
    double ao;

public:
    SoPhuc(double thuc, double ao);
    SoPhuc(double thuc);

    SoPhuc operator+(SoPhuc sp);
    SoPhuc operator-(SoPhuc sp);
    SoPhuc operator*(SoPhuc sp);
    SoPhuc operator/(SoPhuc sp);

    bool operator==(SoPhuc sp);
    bool operator!=(SoPhuc sp);

    friend ostream& operator<<(ostream& os, SoPhuc sp);
    friend istream& operator>>(istream& is, SoPhuc& sp);
};

#endif // SOPHUC_H_INCLUDED

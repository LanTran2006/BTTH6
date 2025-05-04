#ifndef DATHUC_H_INCLUDED
#define DATHUC_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;

class DaThuc {
private:
    vector<int> he_so;
    void chuan_hoa();

public:
    DaThuc();
    DaThuc(const vector<int>& hs);

    friend istream& operator>>(istream& is, DaThuc& dt);
    friend ostream& operator<<(ostream& os, const DaThuc& dt);

    DaThuc operator+(const DaThuc& dt) const;
    DaThuc operator-(const DaThuc& dt) const;
    DaThuc operator*(const DaThuc& dt) const;

    int operator()(int x) const;
};

#endif // DATHUC_H_INCLUDED

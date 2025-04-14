#ifndef BAI6_H_INCLUDED
#define BAI6_H_INCLUDED
#include<bits/stdc++.h>
using namespace std;

class cCandidate {
private:
    string ma, ten, ngaySinh;
    double toan, van, anh;
public:
    cCandidate(string m, string t, string ns, double to, double v, double a);
    double tongDiem() const;
    void xuat() const;
};

class cListCandidate {
private:
    vector<cCandidate> danhSach;
public:
    void nhapDanhSach(int n);
    void xuatDanhSachLonHon15() const;
    void thiSinhDiemCaoNhat() const;
    void sapXepGiamDan();
    void xuatDanhSach() const;
};


#endif // BAI6_H_INCLUDED

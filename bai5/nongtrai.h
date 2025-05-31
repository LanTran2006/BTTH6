#ifndef NONGTRAI_H_INCLUDED
#define NONGTRAI_H_INCLUDED

#include <bits/stdc++.h>
using namespace std;

class GiaSuc {
protected:
    int soLuong;
public:
    GiaSuc(int sl);
    virtual string keu() = 0;
    virtual int sinhCon() = 0;
    virtual int choSua() = 0;
    int getSoLuong();
    void tangSoLuong(int slMoi);
};

class Bo : public GiaSuc {
public:
    Bo(int sl);
    string keu();
    int sinhCon();
    int choSua();
};

class Cuu : public GiaSuc {
public:
    Cuu(int sl);
    string keu();
    int sinhCon();
    int choSua();
};

class De : public GiaSuc {
public:
    De(int sl);
    string keu();
    int sinhCon();
    int choSua();
};

class TrangTrai {
private:
    Bo* bo;
    Cuu* cuu;
    De* de;
public:
    TrangTrai(int slBo, int slCuu, int slDe);
    void giaSucDoi();
    void thongKe();
    ~TrangTrai();
};

#endif // NONGTRAI_H_INCLUDED

#ifndef DAGIAC_H_INCLUDED
#define DAGIAC_H_INCLUDED
#include<bits/stdc++.h>
using namespace std;
class Diem {
protected:
    double x, y;

public:
    Diem(double x = 0, double y = 0);
    void setXY(double xVal, double yVal);
    double getX() const;
    double getY() const;
    void Xuat() const;
    void tinhTien(double dx, double dy);
    void phongTo(double scale);
    void quay(double alpha);
};
class DaGiac {
private:
    int n;
    std::vector<Diem> dg;

public:
    DaGiac();
    DaGiac(const DaGiac& fi);
    DaGiac(int num, std::vector<Diem> points);
    ~DaGiac();

    void Nhap();
    void Xuat();
    void tinhTien(double dx, double dy);
    void phongTo(double scale);
    void quay(double alpha);
};

#endif // DAGIAC_H_INCLUDED

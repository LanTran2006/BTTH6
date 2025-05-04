#include "cTime.h"

CTime::CTime(int g, int p, int s) {
    gio = g;
    phut = p;
    giay = s;
    chuanHoa();
}

void CTime::chuanHoa() {
    int total = gio * 3600 + phut * 60 + giay;
    if (total < 0) total = 0;

    gio = (total / 3600) % 24;
    phut = (total % 3600) / 60;
    giay = total % 60;
}

CTime CTime::operator+(int s) {
    return CTime(gio, phut, giay + s);
}

CTime CTime::operator-(int s) {
    return CTime(gio, phut, giay - s);
}

CTime& CTime::operator++() {
    *this = *this + 1;
    chuanHoa();
    return *this;
}

CTime CTime::operator++(int) {
    CTime temp = *this;
    *this = *this + 1;
    chuanHoa();
    return temp;
}

CTime& CTime::operator--() {
    *this = *this - 1;
     chuanHoa();
    return *this;
}

CTime CTime::operator--(int) {
    CTime temp = *this;
    *this = *this - 1;
     chuanHoa();
    return temp;
}

istream& operator>>(istream& is, CTime& t) {
    cout << "Nhap gio: "; is >> t.gio;
    cout << "Nhap phut: "; is >> t.phut;
    cout << "Nhap giay: "; is >> t.giay;
    t.chuanHoa();
    return is;
}

ostream& operator<<(ostream& os, const CTime& t) {
    //in ra cho dep
    os << setw(2) << setfill('0') << t.gio << ":"
       << setw(2) << setfill('0') << t.phut << ":"
       << setw(2) << setfill('0') << t.giay;
    return os;
}

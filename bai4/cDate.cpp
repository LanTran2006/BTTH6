#include "cdate.h"

bool CDate::isLeap(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int CDate::getDaysInMonth(int m, int y) const {
    int days[] = { 31, 28 + isLeap(y), 31, 30, 31, 30,
                   31, 31, 30, 31, 30, 31 };
    return days[m - 1];
}

CDate::CDate(int d, int m, int y) {
    ngay = d;
    thang = m;
    nam = y;
    chuanHoa();
}

void CDate::chuanHoa() {
    while (ngay > getDaysInMonth(thang, nam)) {
        ngay -= getDaysInMonth(thang, nam);
        thang++;
        if (thang > 12) {
            thang = 1;
            nam++;
        }
    }

    while (ngay < 1) {
        thang--;
        if (thang < 1) {
            thang = 12;
            nam--;
        }
        ngay += getDaysInMonth(thang, nam);
    }
}

CDate CDate::operator+(int days) {
    CDate temp = *this;
    temp.ngay += days;
    temp.chuanHoa();
    return temp;
}

CDate CDate::operator-(int days) {
    CDate temp = *this;
    temp.ngay -= days;
    temp.chuanHoa();
    return temp;
}

int CDate::operator-(const CDate& other) const {
    auto countDays = [](CDate d) {
        int days = d.ngay;
        for (int y = 1; y < d.nam; y++)
            days += (365 + (CDate().isLeap(y) ? 1 : 0));
        for (int m = 1; m < d.thang; m++)
            days += d.getDaysInMonth(m, d.nam);
        return days;
    };
    return abs(countDays(*this) - countDays(other));
}

CDate& CDate::operator++() {
    *this = *this + 1;
    chuanHoa();
    return *this;
}

CDate CDate::operator++(int) {
    CDate temp = *this;
    *this = *this + 1;
    chuanHoa();
    return temp;
}

CDate& CDate::operator--() {
    *this = *this - 1;
    chuanHoa();
    return *this;
}

CDate CDate::operator--(int) {
    CDate temp = *this;
    *this = *this - 1;
    chuanHoa();
    return temp;
}

istream& operator>>(istream& is, CDate& d) {
    cout << "Nhap ngay thang nam "; is >> d.ngay>>d.thang>>d.nam;
    d.chuanHoa();
    return is;
}

ostream& operator<<(ostream& os, const CDate& d) {
    //xuat cho dep
    os << setw(2) << setfill('0') << d.ngay << "/"
       << setw(2) << setfill('0') << d.thang << "/"
       << d.nam;
    return os;
}

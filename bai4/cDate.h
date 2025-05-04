#ifndef CDATE_H_INCLUDED
#define CDATE_H_INCLUDED

#ifndef CDATE_H
#define CDATE_H

#include <bits/stdc++.h>
using namespace std;

class CDate {
private:
    int ngay, thang, nam;

    bool isLeap(int y) const;
    int getDaysInMonth(int m, int y) const;
    void chuanHoa();

public:
    CDate(int d = 1, int m = 1, int y = 2000);

    CDate operator+(int days);
    CDate operator-(int days);
    int operator-(const CDate& other) const;

    CDate& operator++();
    CDate operator++(int);
    CDate& operator--();
    CDate operator--(int);

    friend istream& operator>>(istream& is, CDate& d);
    friend ostream& operator<<(ostream& os, const CDate& d);
};

#endif


#endif // CDATE_H_INCLUDED

#ifndef CTIME_H_INCLUDED
#define CTIME_H_INCLUDED

#include <bits/stdc++.h>
using namespace std;

class CTime {
private:
    int gio, phut, giay;

    void chuanHoa();

public:
    CTime(int g = 0, int p = 0, int s = 0);

    CTime operator+(int s);
    CTime operator-(int s);

    CTime& operator++();
    CTime operator++(int);
    CTime& operator--();
    CTime operator--(int);

    friend istream& operator>>(istream& is, CTime& t);
    friend ostream& operator<<(ostream& os, const CTime& t);
};

#endif // CTIME_H_INCLUDED

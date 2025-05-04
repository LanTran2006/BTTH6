#include "phanso.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
    PhanSo a, b;

    // Nhap hai phan so
    cout << "Nhap phan so thu nhat:\n";
    cin >> a;
    cout << "Nhap phan so thu hai:\n";
    cin >> b;

    // Hien thi phan so
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // Tinh toan cac phep + - * /
    PhanSo cong = a + b;
    PhanSo tru = a - b;
    PhanSo nhan = a * b;
    PhanSo chia = a / b;

    // So sanh hai phan so
    bool bang = (a == b);
    bool khongBang = (a != b);
    bool nhoHon = (a < b);
    bool lonHon = (a > b);

    //  ket qua tinh toan
    cout << "a + b = " << cong << endl;
    cout << "a - b = " << tru << endl;
    cout << "a * b = " << nhan << endl;
    cout << "a / b = " << chia << endl;

    // ket qua so sanh
    cout << "a == b => " << (bang ? "true" : "false") << endl;
    cout << "a != b => " << (khongBang ? "true" : "false") << endl;
    cout << "a < b => " << (nhoHon ? "true" : "false") << endl;
    cout << "a > b => " << (lonHon ? "true" : "false") << endl;

    return 0;
}

#include "sophuc.h"

int main() {
    SoPhuc a(0), b(0);

    cout << "Nhap so phuc a:\n";
    cin >> a;

    cout << "Nhap so phuc b:\n";
    cin >> b;

    SoPhuc tong = a + b;
    SoPhuc hieu = a - b;
    SoPhuc tich = a * b;
    SoPhuc thuong = a / b;

    cout << "\na = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << tong << endl;
    cout << "a - b = " << hieu << endl;
    cout << "a * b = " << tich << endl;
    cout << "a / b = " << thuong << endl;

    if (a == b)
        cout << "a bang b" << endl;
    else
        cout << "a khac b" << endl;

    return 0;
}

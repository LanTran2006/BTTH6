#include "cDate.h"
using namespace std;

int main()
{
    CDate d1, d2;

    cout << "Nhap ngay thang nam cho d1:\n";
    cin >> d1;
    cout << "Nhap ngay thang nam cho d2:\n";
    cin >> d2;

    cout << "\nNgay d1: " << d1 << endl;
    cout << "Ngay d2: " << d2 << endl;

    // cong
    cout << "\nNgay d1 + 10 ngay: " << d1 + 10 << endl;

    // tru
    cout << "Ngay d1 - 5 ngay: " << d1 - 5 << endl;

    // khoang cach giua hai ngay
    cout << "Khoang cach giua d1 va d2: " << (d1 - d2) << " ngay" << endl;

    //  ++d1
    cout << "\nTang 1 ngay ++d1: " << ++d1 << endl;

    // d1++
    cout << "Tang 1 ngay  d1++: " << d1++ << endl;
    cout << "Sau khi tang d1: " << d1 << endl;

    // --d1
    cout << "\nGiam 1 ngay  --d1: " << --d1 << endl;

    // d1--
    cout << "Giam 1 ngay d1--: " << d1-- << endl;
    cout << "Sau khi giam d1: " << d1 << endl;
    return 0;
}

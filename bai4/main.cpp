#include <bits/stdc++.h>
#include"bai4.h"
using namespace std;

int main()
{
     cArray arr(10);
    cout << "Mang ban dau: ";
    arr.xuatMang();

    int x = 10;
    cout << "So lan xuat hien cua " << x << ": " << arr.demXuatHien(x) << endl;
    cout << "Mang co tang dan khong? " << (arr.tangDan() ? "Co" : "Khong") << endl;
    cout << "Phan le nho nhat: " << arr.phanLeNhoNhat() << endl;
    cout << "So nguyen to lon nhat: " << arr.soNguyenToLonNhat() << endl;

    arr.sapXepTangDan();
    cout << "Mang sau khi sap xep tang dan: ";
    arr.xuatMang();

    arr.sapXepGiamDan();
    cout << "Mang sau khi sap xep giam dan: ";
    arr.xuatMang();

    return 0;
}

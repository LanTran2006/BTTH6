#include <bits/stdc++.h>
using namespace std;
class cArray {
private:
    int* arr;
    int n;

public:
    cArray(int size);
    ~cArray();
    void xuatMang();
    int demXuatHien(int x);
    int phanLeNhoNhat();
    bool laSoNguyenTo(int num);
    bool tangDan();
    int soNguyenToLonNhat();
    void sapXepTangDan();
    void sapXepGiamDan();
};
cArray::cArray(int size) {
    n = size;
    arr = new int[n];
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

cArray::~cArray() {
    delete[] arr;
}

void cArray::xuatMang() {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int cArray::demXuatHien(int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) count++;
    }
    return count;
}

bool cArray::tangDan() {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}

int cArray::phanLeNhoNhat() {
    int minOdd = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0 && (minOdd == -1 || arr[i] < minOdd)) {
            minOdd = arr[i];
        }
    }
    return minOdd;
}

bool cArray::laSoNguyenTo(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int cArray::soNguyenToLonNhat() {
    int maxPrime = -1;
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(arr[i]) && arr[i] > maxPrime) {
            maxPrime = arr[i];
        }
    }
    return maxPrime;
}


void cArray::sapXepTangDan() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void cArray::sapXepGiamDan() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

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


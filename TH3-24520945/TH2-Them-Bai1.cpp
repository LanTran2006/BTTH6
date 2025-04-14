#include <bits/stdc++.h>
using namespace std;

struct Diem {
    float x, y;
};

class TamGiac {
private:
    Diem A, B, C;
    static int dem;

    float doDai(Diem p1, Diem p2) const {
        return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    }

public:
    TamGiac() {
        A = {0, 0};
        B = {1, 0};
        C = {0, 1};
        dem++;
    }

    TamGiac(Diem a, Diem b, Diem c) {
        A = a;
        B = b;
        C = c;
        dem++;
    }

    void xuat() const {
        cout << "A(" << A.x << ", " << A.y << "), ";
        cout << "B(" << B.x << ", " << B.y << "), ";
        cout << "C(" << C.x << ", " << C.y << ")\n";
    }

    float chuVi() const {
        return doDai(A, B) + doDai(B, C) + doDai(C, A);
    }

    float dienTich() const {
        return 0.5 * fabs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
    }

    bool hopLe() const {
        float a = doDai(B, C);
        float b = doDai(A, C);
        float c = doDai(A, B);
        return a + b > c && a + c > b && b + c > a;
    }

    void phanLoai() const {
        float a = doDai(B, C);
        float b = doDai(A, C);
        float c = doDai(A, B);

        if (!hopLe()) {
            cout << "Khong phai tam giac hop le.\n";
            return;
        }

        if (fabs(a - b) < 1e-5 && fabs(b - c) < 1e-5)
            cout << "Tam giac deu\n";
        else if (fabs(a - b) < 1e-5 || fabs(b - c) < 1e-5 || fabs(a - c) < 1e-5) {
            if (fabs(a * a + b * b - c * c) < 1e-5 ||
                fabs(a * a + c * c - b * b) < 1e-5 ||
                fabs(b * b + c * c - a * a) < 1e-5)
                cout << "Tam giac vuong can\n";
            else
                cout << "Tam giac can\n";
        } else if (fabs(a * a + b * b - c * c) < 1e-5 ||
                   fabs(a * a + c * c - b * b) < 1e-5 ||
                   fabs(b * b + c * c - a * a) < 1e-5)
            cout << "Tam giac vuong\n";
        else
            cout << "Tam giac thuong\n";
    }

    static int laySoTamGiac() {
        return dem;
    }
};

int TamGiac::dem = 0;

int main() {
    vector<TamGiac> danhSach;
    danhSach.push_back(TamGiac({0, 0}, {4, 0}, {0, 3})); 
    danhSach.push_back(TamGiac({1, 1}, {2, 4}, {5, 1})); 
    danhSach.push_back(TamGiac({0, 0}, {2, 0}, {1, sqrt(3)}));
    for (int i = 0; i < danhSach.size(); ++i) {
        cout << "\n--- Tam giac " << i + 1 << " ---\n";
        danhSach[i].xuat();

        if (danhSach[i].hopLe()) {
            cout << "Chu vi: " << danhSach[i].chuVi() << endl;
            cout << "Dien tich: " << danhSach[i].dienTich() << endl;
            danhSach[i].phanLoai();
        } else {
            cout << "Tam giac khong hop le.\n";
        }
    }

    cout << "\nSo tam giac da tao: " << TamGiac::laySoTamGiac() << endl;

    return 0;
}


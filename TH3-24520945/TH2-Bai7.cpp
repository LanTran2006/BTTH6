#include <bits/stdc++.h>
using namespace std;

class Vehicle {
private:
    string owner;
    string type;
    double price;
    int dungTich;

public:
    Vehicle(string cx, string lx, double tg, int dt) {
        owner = cx;
        type = lx;
        price = tg >= 0 ? tg : 0;
        dungTich = dt >= 0 ? dt : 0;
    }
    
    Vehicle() {
        cout << "Nhap ten chu xe: "; getline(cin, owner);
        cout << "Nhap loai xe: "; getline(cin, type);
        cout << "Nhap tri gia xe: "; cin >> price;
        cout << "Nhap dung tich xy lanh: "; cin >> dungTich;
        cin.ignore();
        price = price >= 0 ? price : 0;
        dungTich = dungTich >= 0 ? dungTich : 0;
    }
    
    double tinhThue() {
        if (dungTich < 100) return price * 0.01;
        else if (dungTich <= 200) return price * 0.03;
        return price * 0.05;
    }
    
    void xuat() {
        cout << left << setw(15) << owner << setw(15) << type
             << setw(10) << price << setw(10) << dungTich
             << setw(10) << tinhThue() << endl;
    }
};

int main() {
    Vehicle xe1("Nguyen A", "Xe May", 30000, 90);
    Vehicle xe2("Tran lan", "O To", 500000, 250);
    Vehicle xe3;
    
    cout << left << setw(15) << "Chu Xe" << setw(15) << "Loai Xe"
         << setw(10) << "Tri Gia" << setw(10) << "Dung Tich"
         << setw(10) << "Thue" << endl;
    cout << string(60, '-') << endl;
    
    xe1.xuat();
    xe2.xuat();
    xe3.xuat();
    
    return 0;
}


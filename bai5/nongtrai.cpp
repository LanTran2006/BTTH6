#include "nongtrai.h"

// GiaSuc
GiaSuc::GiaSuc(int sl) {
    soLuong = sl;
}

int GiaSuc::getSoLuong() {
    return soLuong;
}

void GiaSuc::tangSoLuong(int slMoi) {
    soLuong += slMoi;
}

// Bo
Bo::Bo(int sl) : GiaSuc(sl) {}

string Bo::keu() {
    return "Cow: Ò ò ò!";
}

int Bo::sinhCon() {
    int tong = 0;
    for (int i = 0; i < soLuong; ++i)
        tong += rand() % 3 + 1;
    return tong;
}

int Bo::choSua() {
    int tong = 0;
    for (int i = 0; i < soLuong; ++i)
        tong += rand() % 21;
    return tong;
}

// Cuu
Cuu::Cuu(int sl) : GiaSuc(sl) {}

string Cuu::keu() {
    return "Cuu: Be be!";
}

int Cuu::sinhCon() {
    int tong = 0;
    for (int i = 0; i < soLuong; ++i)
        tong += rand() % 3 + 1;
    return tong;
}

int Cuu::choSua() {
    int tong = 0;
    for (int i = 0; i < soLuong; ++i)
        tong += rand() % 6;
    return tong;
}

// De
De::De(int sl) : GiaSuc(sl) {}

string De::keu() {
    return "De: Be be!";
}

int De::sinhCon() {
    int tong = 0;
    for (int i = 0; i < soLuong; ++i)
        tong += rand() % 3 + 1;
    return tong;
}

int De::choSua() {
    int tong = 0;
    for (int i = 0; i < soLuong; ++i)
        tong += rand() % 11;
    return tong;
}

// TrangTrai
TrangTrai::TrangTrai(int slBo, int slCuu, int slDe) {
    bo = new Bo(slBo);
    cuu = new Cuu(slCuu);
    de = new De(slDe);
}

void TrangTrai::giaSucDoi() {
    cout << "\n--- Tieng keu khi gia suc doi ---\n";
    cout << bo->keu() << endl;
    cout << cuu->keu() << endl;
    cout << de->keu() << endl;
}

void TrangTrai::thongKe() {
    int sinhBo = bo->sinhCon();
    int sinhCuu = cuu->sinhCon();
    int sinhDe = de->sinhCon();

    bo->tangSoLuong(sinhBo);
    cuu->tangSoLuong(sinhCuu);
    de->tangSoLuong(sinhDe);

    int suaBo = bo->choSua();
    int suaCuu = cuu->choSua();
    int suaDe = de->choSua();

    cout << "\n--- Thong ke sau sinh va cho sua ---\n";
    cout << "Bo: " << bo->getSoLuong() << " con, sua: " << suaBo << " lit\n";
    cout << "Cuu: " << cuu->getSoLuong() << " con, sua: " << suaCuu << " lit\n";
    cout << "De: " << de->getSoLuong() << " con, sua: " << suaDe << " lit\n";
    cout << "Tong sua: " << suaBo + suaCuu + suaDe << " lit\n";
}

TrangTrai::~TrangTrai() {
    delete bo;
    delete cuu;
    delete de;
}

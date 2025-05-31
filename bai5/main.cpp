#include "nongtrai.h"

int main() {
    srand(time(0));
    int slBo, slCuu, slDe;

    cout << "Nhap so luong Bo: ";
    cin >> slBo;
    cout << "Nhap so luong Cuu: ";
    cin >> slCuu;
    cout << "Nhap so luong De: ";
    cin >> slDe;

    TrangTrai tt(slBo, slCuu, slDe);
    tt.giaSucDoi();
    tt.thongKe();

    return 0;
}

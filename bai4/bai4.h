#ifndef BAI4_H_INCLUDED
#define BAI4_H_INCLUDED



#endif // BAI4_H_INCLUDED
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

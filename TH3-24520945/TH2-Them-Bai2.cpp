#include<bits/stdc++.h>
using namespace std;


class PTB1 {
private:
    double a, b;

public:

    PTBac1() {
       a=b=0;
    }
    PTBac1(double b) {
       a=0;
       this->b=b;
    }
    PTBac1(double a, double b) {
        this->a=a;
        this->b=b;
    };

    void setA(double a) {
       this->a=a;
    }
    void setB(double b) {
        this->b=b;
    }


    void nhap() {
        cout<<"nhap a va b: ";
       cin>>a>>b;
    }

    void giaiPT() {
        if (a==0 && b==0) {
            cout<<"pt vo so nghiem";
        } else if (b==0) {
             cout<<"pt co nghiem x=0";
        } else if (a==0 && b!=0) {
             cout<<"pt vo nghiem";
        } else {
            cout<<"pt co nghiem x="<<1.0*(-b)/a;
        }
    }


    void xuatPT() {
        if (b<0) {
            cout<<a<<"x-"<<-b<<"=0";
            return;
        } else if (b==0) {
            cout<<a<<"x"<<"=0";
            return;
        }
        cout<<a<<"x+"<<b<<"=0";
    }
};
int main() {
   PTB1 x;
   x.nhap();
   x.giaiPT();
}

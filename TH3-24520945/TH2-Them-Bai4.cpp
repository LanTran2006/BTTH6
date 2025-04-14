#include <bits/stdc++.h>
using namespace std;

class TamGiac
{
private:
    double a, b, c;

public:

    TamGiac()
    {
        a=b=c=1;
    }
    TamGiac(double a, double b, double c)
    {
        this->a=a;
        this->b=b;
        this->c=c;
    }

    void nhap()
    {
        cout<<"nhap 3 canh tam giac";
        cin>>a>>b>>c;
    }


    bool kiemTraHopLe()
    {
        return (a + b > c) && (a + c > b) && (b + c > a);
    }
    string Phanloai()
    {
        if (a == b && b == c) return "Tam giac deu";

        if (a == b || a == c || b == c)
        {
            if ((a * a + b * b == c * c) ||
                    (a * a + c * c == b * b) ||
                    (b * b + c * c == a * a))
                return "Tam giac vuong can";
            return "Tam giac can";
        }

        if ((a * a + b * b == c * c) ||
                (a * a + c * c == b * b) ||
                (b * b + c * c == a * a))
            return "Tam giac vuong";

        return "Tam giac thuong";
    }


    double chuVi()
    {
        return a+b+c;
    }


    double dienTich()
    {
        double s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }


    void xuat()
    {
        if (!kiemTraHopLe())
        {
            cout<<"ko hop le"<<endl;
            return;
        }
        cout<<Phanloai()<<endl;
         cout<<"chu vi tam giac: "<<chuVi()<<endl;
        cout<<"dien tich tam giac: "<<dienTich()<<endl;
    }
};

int main()
{
   TamGiac x(1,1,3);
   x.xuat();
}

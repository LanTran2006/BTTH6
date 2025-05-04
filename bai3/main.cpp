#include "ctime.h"
#include <windows.h>

int main() {
    CTime t;
    cin >> t;

    cout << "\n=== Dong ho  ===\n";
    while (true) {
        system("cls");
        cout << "\n\t\t\t\t\tDong ho: " << t << endl;
        Sleep(1000);
        ++t;
    }

    return 0;
}


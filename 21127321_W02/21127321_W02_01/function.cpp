#include "header.h"

bool chiChuCai(string str) {
    return str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") == string::npos;
}
bool chiSo(string str) {
    return str.find_first_not_of("0123456789") == string::npos;
}
void Hocsinh::Input()
{
    while (true) {
        cout << "Nhap ho ten: " << endl;
        getline(cin, Hoten);
        if (Hoten.length() <= 20 && chiChuCai(Hoten)) break;
    }
    while (true) {
        cout << "Nhap so dien thoai: " << endl;
        getline(cin, Sdt);
        if (Sdt.length() <= 20 && chiSo(Sdt)) break;
    }
    while (true) {
        cout << "Nhap diem: " << endl;
        cin >> Dtb;
        if (Dtb>=0 && Dtb<=10) break;
    }
}
void Hocsinh::Output() {
    cout << "Ho ten: " << Hoten << endl;
    cout << "So dien thoai: " << Sdt << endl;
    cout << "Diem trung binh: " << Dtb << endl;
}

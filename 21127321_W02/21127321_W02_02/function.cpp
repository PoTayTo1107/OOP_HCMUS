#include "header.h"

ifstream fi("LopHoc.txt");
int n;

bool chiChuCai(string str) {
    return str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") == string::npos;
}
bool chiSo(string str) {
    return str.find_first_not_of("0123456789") == string::npos;
}
bool cmp(Hocsinh hs1, Hocsinh hs2) {
    return hs1.getDtb() > hs2.getDtb();
}
void Hocsinh::InputC()
{
    while (true) {
        cout << "Nhap ho ten: " << endl;
        getline(cin, Hoten);
        if (Hoten.length() <= 20 && chiChuCai(Hoten)) break;
    }
    while (true) {
        cout << "Nhap so dien thoai: " << endl;
        getline(cin, Sdt);
        if (Sdt.length() >=9 && Sdt.length() <= 11 && chiSo(Sdt)) break;
    }
    while (true) {
        cout << "Nhap diem: " << endl;
        cin >> Dtb;
        if (Dtb >= 0 && Dtb <= 10) break;
    }
}
void Hocsinh::Input() {
    getline(fi, Hoten);
    getline(fi, Sdt);
    fi >> Dtb;
    fi.ignore();
}
void Hocsinh::Output() {
    cout << "Ho va ten: " << Hoten << endl;
    cout << "So dien thoai: " << Sdt << endl;
    cout << fixed << setprecision(2) << "Diem trung binh: " << Dtb << endl;
    cout << endl;
}
string Hocsinh::getHoten() {
    return Hoten;
}
float Hocsinh::getDtb() {
    return Dtb;
}
void Lophoc::Add() {
    Hocsinh tmp;
    cout << "Them hoc sinh:" << endl;
    tmp.InputC();
    for (int i = 0; i < Danhsach.size(); i++)
       if (Danhsach[i].getHoten() == tmp.getHoten()) {
                cout << "Da co hoc sinh trong lop." << endl;
                return;
       }
    Danhsach.push_back(tmp);
    cout << "Them hoc sinh thanh cong!" << endl;
    n++;
}
void Lophoc::Remove() {
    string tmp;
    cout << "Xoa hoc sinh:" << endl;
    cout << "Nhap ho va ten: " << endl;
    cin.ignore();
    getline(cin, tmp);
    for (int i = 0; i < Danhsach.size(); i++)
        if (Danhsach[i].getHoten() == tmp) {
            Danhsach.erase(Danhsach.begin()+i);
            cout << "Xoa hoc sinh thanh cong!" << endl;
            n--;
            return;
        }
    cout << "Khong co hoc sinh trong lop!" << endl;
}
void Lophoc::Input() {
    Hocsinh tmp;
    fi >> n;
    fi.ignore();
    for (int i = 0; i < n; i++) {
        tmp.Input();
        Danhsach.push_back(tmp);
    }
}
void Lophoc::Output() {
    for (int i = 0; i < Danhsach.size(); i++)
        Danhsach[i].Output();
}
void Lophoc::Sort() {
    sort(Danhsach.begin(), Danhsach.end(), cmp);
}


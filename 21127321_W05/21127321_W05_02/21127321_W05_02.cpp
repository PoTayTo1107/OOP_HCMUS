#include "header.h"

int main()
{
    MangSoNguyen m1;
    int a[5] = { 1,2,3,4,5 };
    MangSoNguyen m2(a,5);
    MangSoNguyen m3(m2);
    MangSoNguyen m4;

    cout <<"Mang 1 (mac dinh}: "<< m1;

    cout <<"Mang 2 (2 tham so): " << m2;

    cout <<"Mang 3 (sao chep mang 2): " << m3;

    m4 = m2;
    cout <<"Mang 4 = Mang 2: " << m4;

    m4 = m2 + m3;
    cout <<"Mang 4 = Mang 2 + Mang 3:"<< m4;

    m4 = m2++;
    cout << "Mang 4 = Mang 2++ :" << endl; 
    cout << "Mang2:" << m2;
    cout << "Mang4:" << m4;

    m4 = ++m2;
    cout <<"Mang 4 = ++Mang 2 :" << endl;
    cout << "Mang2:" << m2;
    cout << "Mang4:" << m4;

    cout << "Nhap xuat mang so nguyen: " << endl;
    cin >> m4;
    cout << m4;
}


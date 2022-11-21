#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Phanso
{
    int* tuSo, * mauSo;

public:
    Phanso();
    Phanso(int);
    Phanso(int, int);
    Phanso(const Phanso&);
    ~Phanso();
    int getTu();
    int getMau();
    void setTu(int);
    void setMau(int);
    void rutGon();
    void Output1();
    void Output2();
    Phanso& operator=(const Phanso& a); 
    Phanso operator+(const Phanso& a);
    Phanso operator-(const Phanso& a);
    Phanso operator*(const Phanso& a);
    Phanso operator/(const Phanso& a);
    Phanso& operator+=(const Phanso& a);
    Phanso& operator-=(const Phanso& a);
    Phanso& operator*=(const Phanso& a);
    Phanso& operator/=(const Phanso& a);
    bool operator==(const Phanso& a);
    bool operator>(const Phanso& a);
    bool operator<(const Phanso& a);
    bool operator>=(const Phanso& a);
    bool operator<=(const Phanso& a);
    bool operator!=(const Phanso& a);
    Phanso& operator++();
    Phanso& operator--();
    Phanso operator++(int);
    Phanso operator--(int);
    friend istream& operator>> (istream&, Phanso&);
    friend ostream& operator<< (ostream&, Phanso&);
};
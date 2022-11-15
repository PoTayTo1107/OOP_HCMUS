#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Phanso
{
    int *tuSo, *mauSo;

public:
    Phanso();
    Phanso(int);
    Phanso(int,int);
    Phanso(const Phanso &);
    ~Phanso();
    int getTu();
    int getMau();
    void setTu(int);
    void setMau(int);
    void rutGon();
    void Output1();
    void Output2();
    Phanso operator+(Phanso);
    Phanso operator-(Phanso);
    Phanso operator*(Phanso);
    Phanso operator/(Phanso);
};
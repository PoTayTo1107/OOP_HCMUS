#include "header.h"

Phanso::Phanso() {
    tuSo = new int;
    mauSo = new int;
    *tuSo = 0;
    *mauSo = 1;
}

Phanso::Phanso(int tu) {
    tuSo = new int;
    mauSo = new int;
    *tuSo = tu;
    *mauSo = 1;
}

Phanso::Phanso(int tu, int mau) {
    tuSo = new int;
    mauSo = new int;
    *tuSo = tu;
    *mauSo = mau;
}

Phanso::Phanso(const Phanso &temp) {
    tuSo = new int;
    mauSo = new int;
    *tuSo = *temp.tuSo;
    *mauSo = *temp.mauSo;
}

Phanso::~Phanso(){}

void Phanso::Output1()
{
    cout << this->getTu() << "/" << this->getMau() << " ";
}

void Phanso::Output2()
{
    float tmp = (float)this->getTu() / (float)this->getMau();
    cout << fixed << setprecision(2) << tmp << endl;
}

int Phanso::getTu()
{
   return *tuSo;
}

int Phanso::getMau()
{
    return *mauSo;
}

void Phanso::setMau(int mau)
{
    if (mau == 0)
        return;
    *mauSo = mau;
}

void Phanso::setTu(int tu)
{
    *tuSo = tu;
}

Phanso Phanso::operator+(Phanso a)
{
    Phanso ans;
    if (this->getMau() == a.getMau())
    {
        ans.setTu(this->getTu() + a.getTu());
        ans.setMau(a.getMau());
    }
    else
    {
        ans.setTu(this->getTu() * a.getMau() + a.getTu() * this->getMau());
        ans.setMau(this->getMau() * a.getMau());
    }
    ans.rutGon();
    return ans;
}

Phanso Phanso::operator-(Phanso a)
{
    Phanso ans;
    if (this->getMau() == a.getMau())
    {
        ans.setTu(this->getTu() + a.getTu());
        ans.setMau(a.getMau());
    }
    else
    {
        ans.setTu(this->getTu() * a.getMau() - a.getTu() * this->getMau());
        ans.setMau(this->getMau() * a.getMau());
    }
    ans.rutGon();
    return ans;
}

Phanso Phanso::operator*(Phanso a)
{
    Phanso ans;
    ans.setTu(*tuSo * a.getTu());
    ans.setMau(*mauSo * a.getMau());
    ans.rutGon();
    return ans;
}

Phanso Phanso::operator/(Phanso a)
{
    Phanso ans;
    if (a.getTu() == 0)
    {
        cout << "Khong the chia cho 0" << endl;
    }
    ans.setTu(*tuSo * a.getMau());
    ans.setMau(*mauSo * a.getTu());
    ans.rutGon();
    return ans;
}

int GCD(int a, int b)
{
    return b == 0 ? a : GCD(b, a % b);
}

void Phanso::rutGon()
{
    int gcd = abs(GCD(*tuSo, *mauSo));
    if (*mauSo < 0)
    {
        *tuSo = *tuSo * -1;
        *mauSo = *mauSo * -1;
    }
    *tuSo = *tuSo / gcd;
    *mauSo = *mauSo / gcd;
}

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

Phanso::Phanso(const Phanso& temp) {
    tuSo = new int;
    mauSo = new int;
    *tuSo = *temp.tuSo;
    *mauSo = *temp.mauSo;
}

Phanso::~Phanso() {}

int GCD(int a, int b)
{
    return b == 0 ? a : GCD(b, a % b);
}

void Phanso::rutGon()
{
    int gcd = abs(GCD(*this->tuSo, *this->mauSo));
    if (*this->mauSo < 0)
    {
        *this->tuSo = *this->tuSo * -1;
        *this->mauSo = *this->mauSo * -1;
    }
    *this->tuSo = *this->tuSo / gcd;
    *this->mauSo = *this->mauSo / gcd;
}

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

Phanso& Phanso::operator=(const Phanso& a) {
    if (this == &a) return *this;
    this->tuSo = a.tuSo;
    this->mauSo = a.mauSo;
    return *this;
}

Phanso Phanso::operator+(const Phanso &a)
{
    Phanso ans;
    if (*this->mauSo == *a.mauSo)
    {
        *ans.tuSo = *this->tuSo + *a.tuSo;
        *ans.mauSo = *a.mauSo;
    }
    else
    {
        *ans.tuSo = *this->tuSo * *a.mauSo + *a.tuSo * *this->mauSo;
        *ans.mauSo = *this->mauSo * *a.mauSo;
    }
    ans.rutGon();
    return ans;
}

Phanso Phanso::operator-(const Phanso& a)
{
    Phanso ans;
    if (*this->mauSo == *a.mauSo)
    {
        *ans.tuSo = *this->tuSo - *a.tuSo;
        *ans.mauSo = *a.mauSo;
    }
    else
    {
        *ans.tuSo = *this->tuSo * *a.mauSo - *a.tuSo * *this->mauSo;
        *ans.mauSo = *this->mauSo * *a.mauSo;
    }
    ans.rutGon();
    return ans;
}

Phanso Phanso::operator*(const Phanso& a)
{
    Phanso ans;
    *ans.tuSo = *this->tuSo * *a.tuSo;
    *ans.mauSo = *this->mauSo * *a.mauSo;
    ans.rutGon();
    return ans;
}

Phanso Phanso::operator/(const Phanso& a)
{
    Phanso ans;
    if (*a.mauSo == 0)
    {
        cout << "Khong the chia cho 0" << endl;
    }
    *ans.tuSo = *this->tuSo * *a.mauSo;
    *ans.mauSo = *this->mauSo * *a.tuSo;
    ans.rutGon();
    return ans;
}

Phanso& Phanso::operator+=(const Phanso& a)
{
    if (*this->mauSo == *a.mauSo)
    {
        *this->tuSo = *this->tuSo + *a.tuSo;
    }
    else
    {
        *this->tuSo = *this->tuSo * *a.mauSo + *a.tuSo * *this->mauSo;
        *this->mauSo = *this->mauSo * *a.mauSo;
    }
    this->rutGon();
    return *this;
}

Phanso& Phanso::operator-=(const Phanso& a)
{
    if (*this->mauSo == *a.mauSo)
    {
        *this->tuSo = *this->tuSo - *a.tuSo;
    }
    else
    {
        *this->tuSo = *this->tuSo * *a.mauSo - *a.tuSo * *this->mauSo;
        *this->mauSo = *this->mauSo * *a.mauSo;
    }
    this->rutGon();
    return *this;
}

Phanso& Phanso::operator*=(const Phanso& a)
{
    *this->tuSo = *this->tuSo * *a.tuSo;
    *this->mauSo = *this->mauSo * *a.mauSo;
    this->rutGon();
    return *this;
}

Phanso& Phanso::operator/=(const Phanso& a)
{
    if (*this->mauSo == 0)
    {
        cout << "Khong the chia cho 0" << endl;
    }
    *this->tuSo = *this->tuSo * *a.mauSo;
    *this->mauSo = *this->mauSo * *a.tuSo;
    this->rutGon();
    return *this;
}

bool Phanso::operator==(const Phanso& a) {
    int result = *this->tuSo * *a.mauSo - *this->mauSo * *a.tuSo;
    return (result == 0);
}

bool Phanso::operator>(const Phanso& a) {
    int result = *this->tuSo * *a.mauSo - *this->mauSo * *a.tuSo;
    return (result > 0);
}

bool Phanso::operator<(const Phanso& a) {
    int result = *this->tuSo * *a.mauSo - *this->mauSo * *a.tuSo;
    return (result < 0);
}

bool Phanso::operator>=(const Phanso& a) {
    int result = *this->tuSo * *a.mauSo - *this->mauSo * *a.tuSo;
    return (result >= 0);
}

bool Phanso::operator<=(const Phanso& a) {
    int result = *this->tuSo * *a.mauSo - *this->mauSo * *a.tuSo;
    return (result <= 0);
}

bool Phanso::operator!=(const Phanso& a) {
    int result = *this->tuSo * *a.mauSo - *this->mauSo * *a.tuSo;
    return (result != 0);
}

Phanso& Phanso::operator++() {
    *this->tuSo = *this->tuSo + *this->mauSo;
    return *this;
}

Phanso& Phanso::operator--() {
    *this->tuSo = *this->tuSo - *this->mauSo;
    return *this;
}

Phanso Phanso::operator++(int x) {
    Phanso result(*this);
    *this->tuSo = *this->tuSo + *this->mauSo;
    return result;
}

Phanso Phanso::operator--(int x) {
    Phanso result(*this);
    *this->tuSo = *this->tuSo - *this->mauSo;
    return result;
}

istream& operator>> (istream& is, Phanso& a)
{
    cout << "Nhap tu so: ";
    is >> *a.tuSo;
    cout << "Nhap mau so: ";
    is >> *a.mauSo;
    return is;
}

ostream& operator<< (ostream& os, Phanso& a)
{
    os << "Phan so da nhap la: " << *a.tuSo << "/" << *a.mauSo << '\n';
    return os;
} 
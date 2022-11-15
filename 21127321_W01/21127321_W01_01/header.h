#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Fraction
{
    int Numerator, Denominator;

public:
    Fraction Input();
    void Output1();
    void Output2();
    int getNum();
    int getDeno();
    void setNum(int);
    void setDeno(int);
    void Reduce();
    Fraction operator+(Fraction);
    Fraction operator-(Fraction);
    Fraction operator*(Fraction);
    Fraction operator/(Fraction);
};
#include "header.h"

istream& operator>>(istream& inDev, Fraction& ps)
{
    int num, deno;
    inDev >> num >> deno;
    ps.setDeno(deno);
    ps.setNum(num);
    return inDev;
}

int main()
{
    Fraction ps1, ps2;
    // ps1 = ps1.Input();
    // ps2 = ps2.Input();
    cout << "Input Fraction:\n";
    cin >> ps1 >> ps2;
    cout << "Fraction 1: ";
    ps1.Output1();
    ps1.Output2();
    cout << "Fraction 2: ";
    ps2.Output1();
    ps2.Output2();

    Fraction ans;
    cout << "+: ";
    ans = ps1 + ps2;
    ans.Output1();
    ans.Output2();

    cout << "-: ";
    ans = ps1 - ps2;
    ans.Output1();
    ans.Output2();

    cout << "*: ";
    ans = ps1 * ps2;
    ans.Output1();
    ans.Output2();

    cout << "/: ";
    ans = ps1 / ps2;
    ans.Output1();
    ans.Output2();

    return 0;
}
#include "header.h"

int main()
{
    Phanso ps1;
    Phanso ps2(5);
    Phanso ps3(5, 2);
    Phanso ps4(ps3);

    cout << "Phanso 1 (mac dinh): ";
    ps1.Output1();
    ps1.Output2();
    cout << "Phanso 2 (1 tham so): ";
    ps2.Output1();
    ps2.Output2();
    cout << "Phanso 3 (2 tham so): ";
    ps3.Output1();
    ps3.Output2();
    cout << "Phanso 4 (sao chep): ";
    ps4.Output1();
    ps4.Output2();

    cout << '\n';
    
    Phanso ans;
    ps2.Output1();
    cout << "+ ";
    ps3.Output1();
    cout << "= ";
    ans = ps2 + ps3;
    ans.Output1();
    ans.Output2();

    ps2.Output1();
    cout << "- ";
    ps3.Output1();
    cout << "= ";
    ans = ps2 - ps3;
    ans.Output1();
    ans.Output2();

    ps2.Output1();
    cout << "* ";
    ps3.Output1();
    cout << "= ";
    ans = ps2 * ps3;
    ans.Output1();
    ans.Output2();

    ps2.Output1();
    cout << "/ ";
    ps3.Output1();
    cout << "= ";
    ans = ps2 / ps3;
    ans.Output1();
    ans.Output2();

    ps2.Output1();
    cout << "+= ";
    ps3.Output1();
    cout << "-> ";
    ps2 += ps3;
    ps2.Output1();
    ps2.Output2();

    ps2.Output1();
    cout << "-= ";
    ps3.Output1();
    cout << "-> ";
    ps2 -= ps3;
    ps2.Output1();
    ps2.Output2();

    ps2.Output1();
    cout << "*= ";
    ps3.Output1();
    cout << "-> ";
    ps2 *= ps3;
    ps2.Output1();
    ps2.Output2();

    ps2.Output1();
    cout << "/= ";
    ps3.Output1();
    cout << "-> ";
    ps2 /= ps3;
    ps2.Output1();
    ps2.Output2();

    ps2.Output1();
    cout << "== ";
    ps3.Output1();
    cout << "-> ";
    if (ps2 == ps3) cout << "Dung" << endl;
    else cout << "Sai" << endl;

    ps2.Output1();
    cout << "> ";
    ps3.Output1();
    cout << "-> ";
    if (ps2 > ps3) cout << "Dung" << endl;
    else cout << "Sai" << endl;

    ps2.Output1();
    cout << "< ";
    ps3.Output1();
    cout << "-> ";
    if (ps2 < ps3) cout << "Dung" << endl;
    else cout << "Sai" << endl;

    ps2.Output1();
    cout << ">= ";
    ps3.Output1();
    cout << "-> ";
    if (ps2 >= ps3) cout << "Dung" << endl;
    else cout << "Sai" << endl;

    ps2.Output1();
    cout << "<= ";
    ps3.Output1();
    cout << "-> ";
    if (ps2 <= ps3) cout << "Dung" << endl;
    else cout << "Sai" << endl;

    ps2.Output1();
    cout << "!= ";
    ps3.Output1();
    cout << "-> ";
    if (ps2 != ps3) cout << "Dung" << endl;
    else cout << "Sai" << endl;

    cout << '\n';

    cout << "ps2: ";
    ps2.Output1();
    cout << '\n';
    cout << "ans = ps2++ -> ";
    ans = ps2++;
    cout << "ans: ";
    ans.Output1();
    cout << "ps2: ";
    ps2.Output1();
    cout << '\n';

    cout << '\n';

    cout << "ps2: ";
    ps2.Output1();
    cout << '\n';
    cout << "ans = ps2-- -> ";
    ans = ps2--;
    cout << "ans: ";
    ans.Output1();
    cout << "ps2: ";
    ps2.Output1();
    cout << '\n';

    cout << '\n';

    cout << "ps2: ";
    ps2.Output1();
    cout << '\n';
    cout << "ans = ++ps2 -> ";
    ans = ++ps2;
    cout << "ans: ";
    ans.Output1();
    cout << "ps2: ";
    ps2.Output1();
    cout << '\n';

    cout << '\n';

    cout << "ps2: ";
    ps2.Output1();
    cout << '\n';
    cout << "ans = --ps2 -> ";
    ans = --ps2;
    cout << "ans: ";
    ans.Output1();
    cout << "ps2: ";
    ps2.Output1();
    cout << '\n';

    cout << '\n';

    Phanso ps5;
    cin >> ps5;
    cout << ps5;

    return 0;
}
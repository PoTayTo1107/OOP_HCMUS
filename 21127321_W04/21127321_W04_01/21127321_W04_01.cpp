#include "header.h"

int main()
{
    Phanso ps1;
    Phanso ps2(5);
    Phanso ps3(5,2);
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

    Phanso ans;
    cout << "Cac phep tinh voi Phanso2 va Phanso3:\n";
    cout << "+: ";
    ans = ps2 + ps3;
    ans.Output1();
    ans.Output2();
  
    cout << "-: ";
    ans = ps2 - ps3;
    ans.Output1();
    ans.Output2();

    cout << "*: ";
    ans = ps2 * ps3;
    ans.Output1();
    ans.Output2();

    cout << "/: ";
    ans = ps2 / ps3;
    ans.Output1();
    ans.Output2();
   
    return 0;
}
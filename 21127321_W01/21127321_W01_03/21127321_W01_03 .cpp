#include "header.h"

istream& operator>>(istream& inDev, Point& ps)
{
    float x, y;
    inDev >> x >> y;
    ps.setX(x);
    ps.setY(y);
    return inDev;
}

int main()
{
    Point p1, p2, p3, p4;
    cout << "Input:" << endl;
    cin >> p1 >> p2 >> p3 >> p4;
    cout << "P1: " << p1.getX() << " " << p1.getY() << endl;
    cout << "P2: " << p2.getX() << " " << p2.getY() << endl;
    cout << "P3: " << p3.getX() << " " << p3.getY() << endl;
    cout << "P4: " << p4.getX() << " " << p4.getY() << endl;
    Check(p1.getX(), p1.getY(), p2.getX(), p2.getY(), p3.getX(), p3.getY(), p4.getX(), p4.getY());
    return 0;
}
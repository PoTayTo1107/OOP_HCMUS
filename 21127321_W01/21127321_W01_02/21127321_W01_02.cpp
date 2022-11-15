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
    Point p1, p2;
    cout << "Input:" << endl;
    cin >> p1 >> p2;
    cout <<"P1: "<< p1.getX() <<" "<< p1.getY() << endl;
    cout <<"P2: "<< p2.getX() <<" "<< p2.getY() << endl;
    cout << "Distance: " << sqrt((p2.getX() - p1.getX()) * (p2.getX() - p1.getX()) + (p2.getY() - p1.getY()) * (p2.getY() - p1.getY()));
    return 0;
}
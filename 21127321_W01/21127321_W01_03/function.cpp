#include "header.h"

float Point::getX()
{
    return x;
}
float Point::getY()
{
    return y;
}
void Point::setX(float _x)
{
    x = _x;
}
void Point::setY(float _y)
{
    y = _y;
}
void Check(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
    if ((x1 == x4) && (y1 == y2) && (x2 == x3) && (y3 == y4)) {
        cout << "Hinh chu nhat" << endl;
        float e1 = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)), e2 = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
        cout << "Chu vi: " << (e1 + e2) * 2 << endl;
        cout << "Dien tich: " << e1 * e2;
    } 
    else cout << "Khong la hinh chu nhat" << endl;
}
#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Point
{
private:
    float x, y;

public:
    float getX();
    float getY();
    void setX(float);
    void setY(float);
};
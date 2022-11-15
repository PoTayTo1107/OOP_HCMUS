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

void Check(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
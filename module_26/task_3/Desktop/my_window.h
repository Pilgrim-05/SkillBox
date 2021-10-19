#pragma once
#include "point.h"

class My_window
{
private:
    Point point;
    int width;
    int height;

public:
    My_window();
    int getWidth();
    int getHeight();
    Point getPoint();

    void setWidth(const int);
    void setHeight(const int);
    void setPoint(Point &, int, int);
};

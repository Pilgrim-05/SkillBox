#include "point.h"

Point::Point()
{
}

int Point::getX()
{
    return x;
}

int Point::getY()
{
    return y;
}

void Point::setX(const int x)
{
    if(x < 0) Point::x = 0;
    else Point::x = x;
}

void Point::setY(const int y)
{
    if(y < 0) Point::y = 0;
    else Point::y = y;
}

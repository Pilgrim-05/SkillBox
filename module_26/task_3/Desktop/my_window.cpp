#include "my_window.h"

My_window::My_window()
{
    point.setX(0);
    point.setY(0);
    width = 10;
    height = 5;
}

int My_window::getWidth()
{
    return width;
}

int My_window::getHeight()
{
    return height;
}

Point My_window::getPoint()
{
    return point;
}

void My_window::setWidth(const int width)
{
    if(width >= 0) My_window::width = width;
}

void My_window::setHeight(const int height)
{
    if(height >= 0) My_window::height = height;
}

void My_window::setPoint(Point &p, int maxWidth, int maxHeight)
{
    if(p.getX() > maxWidth - 1) p.setX(maxWidth - 1);
    if(p.getY() > maxHeight - 1) p.setY(maxHeight - 1);
    point.setX(p.getX());
    point.setY(p.getY());
}

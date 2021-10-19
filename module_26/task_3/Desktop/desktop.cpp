#include "desktop.h"
#include <iostream>

Desktop::Desktop()
{
    desktopWidth = 80;
    desktopHeight = 50;
}

int Desktop::getDesktopWidth()
{
    return desktopWidth;
}

int Desktop::getDesktopHeight()
{
    return desktopHeight;
    window.getPoint().getY();
}

void Desktop::display()
{
    for(int i = 0; i < desktopHeight; ++i)
    {
        for(int j = 0; j < desktopWidth; ++j)
        {
            if(i < window.getPoint().getY() || j < window.getPoint().getX() ||
                    i > (window.getHeight() + window.getPoint().getY() - 1) ||
                    j > (window.getWidth()  + window.getPoint().getX() - 1))
            {
                std::cout << "0";
            }else
            {
                std::cout << "1";
            }
        }
        std::cout << std::endl;
    }
}

void Desktop::move(Point &point)
{
    window.setPoint(point, desktopWidth, desktopHeight);
    std::cout << "New window coordinates X: " << window.getPoint().getX() << " - Y: " << window.getPoint().getY() << std::endl;
}

void Desktop::resize()
{
    std::cout << "Enter new width: ";
    int width;
    std::cin >> width;

    std::cout << "Enter new height: ";
    int height;
    std::cin >> height;
    std::cin.ignore(32767, '\n');

    if(width < 0) width = window.getWidth();
    if(height < 0) height = window.getHeight();

    window.setHeight(height);
    window.setWidth(width);
    std::cout << "New window size height: " << height << " width: " << width << std::endl;
}

void Desktop::close()
{
    Point p;
    p.setX(0);
    p.setY(0);
    window.setPoint(p, desktopWidth, desktopHeight);
    window.setWidth(0);
    window.setHeight(0);
    std::cout << "Window closed." << std::endl;
}

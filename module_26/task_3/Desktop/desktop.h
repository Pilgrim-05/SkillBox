#pragma once
#include "my_window.h"

class Desktop
{
private:
    int desktopWidth;
    int desktopHeight;
    My_window window;
    Point point;

public:
    Desktop();
    int getDesktopWidth();
    int getDesktopHeight();
    void display();
    void move(Point &);
    void resize();
    void setPoint(int x, int y);
    void close();
};

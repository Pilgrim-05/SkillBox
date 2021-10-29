#include <iostream>
#include "shapes.h"

using namespace std;

void inputDate(Point &point, Colors &color);


int main()
{
    cout << "Enter the command(circle/square/triangle/rectangle): ";
    string command;
    getline(cin, command);

    if(command == "circle")
    {
        Point point;
        Colors color;
        inputDate(point, color);

        cout << "Enter the radius: ";
        int radius;
        cin >> radius;

        Circle circle(point, color, radius);
        circle.display();

    }else if(command == "square")
    {
        Point point;
        Colors color;
        inputDate(point, color);

        cout << "Enter the side: ";
        int side;
        cin >> side;

        Square square(point, color, side);
        square.display();

    }else if(command == "triangle")
    {
        Point point;
        Colors color;
        inputDate(point, color);

        cout << "Enter the side: ";
        int side;
        cin >> side;

        Triangle triangle(point, color, side);
        triangle.display();

    }else if(command == "rectangle")
    {
        Point point;
        Colors color;
        inputDate(point, color);

        cout << "Enter the width and height: ";
        int width;
        int height;
        cin >> width >> height;

        Rectangle rectangle(point, color, width, height);
        rectangle.display();

    }else
    {
        cout << "There is no such command!" << endl;
    }

    return 0;
}

void inputDate(Point &point, Colors &color)
{
    cout << "Enter the coordinates of the center (X Y) ";
    int x;
    int y;
    cin >> x >> y;
    point.setPoint(x,y);
    cout << "Enter the number of the corresponding color:"
            << "\n0 - No color"
            << "\n1 - Red"
            << "\n2 - Blue"
            << "\n3 - Green" << endl;

    int iColor;
    cin >> iColor;
    if(iColor == 1)
    {
        color = Colors::RED;
    }else if(iColor == 2)
    {
        color = Colors::BLUE;
    }else if(iColor == 3)
    {
       color = Colors::GREEN;
    }else
    {
        color = Colors::NONE;
    }
}

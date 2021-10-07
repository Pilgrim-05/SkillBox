#include <iostream>
#include "surgery.h"

bool scalpel(point &start, point &end)
{
    std::cout << "Enter the coordinates of the start of the cut: (X, Y)";
    std::cin >> start.x >> start.y;
    std::cout << "Enter the coordinates of the end of the cut: (X, Y)";
    std::cin >> end.x >> end.y;

    std::cout << "incision from " << start.x << ":" << start.y << " to " << end.x << ":" << end.y  << std::endl;
    return true;
}

void hemostat()
{
    point p;
    std::cout << "Enter the coordinates of bleeding: ";
    std::cin >> p.x >> p.y;
    std::cout << "stopping blood at the point " << p.x << ":" << p.y << std::endl;;
}

void tweezers ()
{
    point p;
    std::cout << "Enter the coordinates of the action: ";
    std::cin >> p.x >> p.y;
    std::cout << "Capture point " << p.x << ":" << p.y << " with tweezers" << std::endl;
}

bool suture(point &start, point &end)
{
    std::cout << "Sew up from " << start.x << ":" << start.y << " to " << end.x << ":" << end.y  << std::endl;
    return false;
}


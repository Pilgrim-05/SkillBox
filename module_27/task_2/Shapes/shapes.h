#pragma once

class Point
{
    int x;
    int y;
public:
    Point() = default;
    Point(int x, int y);
    void setPoint(int x, int y);
};

enum class Colors
{
    NONE,
    RED,
    BLUE,
    GREEN
};

class Shape
{
private:
    Point point;
    Colors color;

public:
    Shape(Point point, Colors color);
    Colors getColor();
    void setPoint(Point point);
    void setColor(Colors color);
};

//circle, square, triangle, rectangle

class Circle : public Shape
{
private:
    double radius;
    double getSquare();

public:
    Circle(Point point, Colors color, double radius);
    void display();
};

class Triangle : public Shape
{
private:
    double side;
    double getSquare();

public:
    Triangle(Point point, Colors color, double side);
    void display();
};

class Square : public Shape
{
private:
    double side;
    double getSquare();

public:
    Square(Point point, Colors color, double side);

    void display();
};

class Rectangle : public Shape
{
private:
    double width;
    double height;
    double getSquare();

public:
    Rectangle(Point point, Colors color, double, double);
    void display();
};

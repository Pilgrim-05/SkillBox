#pragma once

struct point
{
    double x;
    double y;
};

bool scalpel(point &, point &); // Скальпель
void hemostat();         // Зажим
void tweezers ();        // Пинцет
bool suture(point &, point &); // Зашивка

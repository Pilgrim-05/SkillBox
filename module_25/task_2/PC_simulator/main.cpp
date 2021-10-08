/*
 * Каждая компонента должна располагаться в отдельном модуле, с отдельным заголовочным файлом.
 * Основной модуль программы (main.cpp) должен считывать пользовательский ввод команды,
 * которая соответствует отдельным функциям устройств:
 * - sum (вычисление суммы),
 * - save (сохранить в файл),
 * - load (загрузить из файла),
 * - input (ввести с клавиатуры),
 * - display (вывести на экран).
 * - exit — выходит из программы.
*/

#include <iostream>
#include "gpu.h"
#include "kbd.h"

using namespace std;

int main()
{
    cout << "Enter the command(sum/save/load/input/display/exit): ";
    string command;
    getline(cin, command);

    while(command != "exit")
    {
        if(command == "sum")
        {

        }else if(command == "save")
        {

        }else if(command == "load")
        {

        }else if(command == "input")
        {

        }else if(command == "display")
        {

        }

        cout << "Enter the command(sum/save/load/input/display/exit): ";
        getline(cin, command);
    }

    return 0;
}



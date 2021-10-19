#include <iostream>
#include "desktop.h"

using namespace std;

int main()
{

    Desktop *dsp = new Desktop();

    string command;
    cout << "Enter your command(move/resize/display/close): ";
    getline(cin, command);

    while(command != "close")
    {
        if(command == "move")
        {
            Point point;
            int x, y;
            cout << "Enter the X coordinate: ";
            cin >> x;
            cout << "Enter the Y coordinate: ";
            cin >> y;
            point.setX(x);
            point.setY(y);
            dsp->move(point);
            cin.ignore(32767, '\n');

        }else if(command == "resize")
        {
            dsp->resize();
        }else if(command == "display")
        {
            dsp->display();
        }

        cout << "Enter your command(move/resize/display/close): ";
        getline(cin, command);
        if(command == "close") dsp->close();
    }

    delete dsp;

    return 0;
}

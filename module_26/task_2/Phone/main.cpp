#include <iostream>
#include "phone.h"

using namespace std;

int main()
{
    Phone *phone = new Phone();

    string command;
    cout << "Enter your command(add/call/sms/exit): ";
    getline(cin, command);

    while(command != "exit")
    {
        if(command == "add")
        {

        }else if(command == "call")
        {

        }else if(command == "sms")
        {

        }

        cout << "Enter your command(add/call/sms/exit): ";
        getline(cin, command);
    }

    delete phone;

    return 0;
}

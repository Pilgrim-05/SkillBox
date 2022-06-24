#include <string>
#include "register.h"


int main()
{
    Register<int, std::string> reg;

    bool flag = true;
    while (flag)
    {
        std::cout << "Enter command(add/remove/print/find/exit): ";
        std::string cmd;
        std::cin >> cmd;


        if(cmd == "add")
            reg.add();
        else if(cmd == "remove")
            reg.remove();
        else if(cmd == "print")
            reg.print();
        else if(cmd == "find")
            reg.find();
        else if(cmd == "exit")
            flag = false;
    }

    return 0;
}

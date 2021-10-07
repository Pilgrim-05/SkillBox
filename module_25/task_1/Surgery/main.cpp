#include <iostream>
#include "surgery.h"

using namespace std;

int main()
{
    point s, e;
    bool status;
    status = scalpel(s, e);
    while(status)
    {
        cout << "Next procedure((H)hemostat/(T)tweezers/(S)suture): ";
        string procedure;
        cin >> procedure;
        if(procedure == "H")
        {
            hemostat();
        }else if(procedure == "T")
        {
            tweezers();
        }else if(procedure == "S")
        {
            status = suture(s, e);
        }
    }

    return 0;
}



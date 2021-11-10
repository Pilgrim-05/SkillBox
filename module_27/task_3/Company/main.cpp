#include <iostream>
#include "employee.h"

bool controlNumeric(const std::string&);
void enterNum(std::string &str);

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
    cout << "Total number of teams: ";
    string groupNum;
    enterNum(groupNum);

    Director boss;
    boss.setManagersNum(stoi(groupNum));
    Manager manager;

    for(int i = 0; i < boss.getManagersNum(); ++i)
    {
        cout << "Number of employees in team " << (i + 1) << " - ";
        string count;
        enterNum(count);
        manager.setWorkers(stoi(count));
        manager.setId(i);
        boss.setManager(i, manager);
    }

    cout << endl << "********************************" << endl;
    while(!boss.isBusy()){
        cout << "Director's decree: ";
        string command;
        enterNum(command);
        boss.setOrder(stoi(command));
    }
    return 0;
}

void enterNum(string &str)
{
    getline(cin, str);
    while(!controlNumeric(str))
    {
        cout << "ERROR: Enter the number: ";
        getline(cin, str);
    }
}

bool controlNumeric(const string& str)
{
    for(int i = 0; i < str.length(); ++i)
        if(str[i] < '0' || str[i] > '9') return false;
    return true;
}

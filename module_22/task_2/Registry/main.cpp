#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string, int> queueLine;
    bool status = true;

    while(status){
        cout << "Your request: ";
        string command;
        getline(cin, command);

        if(command == "Next")
        {
            if(!queueLine.empty())
            {
                cout << queueLine.begin()->first << endl;
                queueLine.erase(queueLine.begin());
            }else {
                cout << "The queue is empty" << endl;
                status = false;
            }

        }else {
            queueLine.insert(make_pair(command, 0));
        }
    }

    return 0;
}

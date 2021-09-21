#include <iostream>
#include <map>
#include <string>

using namespace std;

void addToQueue(const string &, map<string, int> &);

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
                int counter = queueLine.begin()->second;
                queueLine[queueLine.begin()->first]  = --counter;
                if(counter < 0)
                {
                  queueLine.erase(queueLine.begin());
                }

            }else {
                cout << "The queue is empty" << endl;
                status = false;
            }

        }else {
            addToQueue(command, queueLine);
        }
    }
    return 0;
}

void addToQueue(const string &command, map<string, int> &queueLine)
{
  int counter = 0;
  if(queueLine.find(command) == queueLine.end())
  {
    queueLine.insert(make_pair(command, 0));
  }else {
    counter = queueLine.find(command)->second;
    ++counter;
    queueLine[command] = counter;
  }
}

#include <iostream>
#include <string>
#include <map>

using namespace std;

void addPhone(string &, map<string, string> &, map<string, string> &);
string request(string &, map<string, string> &, map<string, string> &);
bool isNum(const string &);

int main()
{
    map<string, string> phBook_numKey;
    map<string, string> phBook_nameKey;

    while(1)
    {
        cout << "Your request: ";
        string command;
        getline(cin, command);

        int space  = command.find(" ");
        if(space > 0)
        {
            addPhone(command, phBook_numKey, phBook_nameKey);
        }else
        {
            cout << request(command, phBook_numKey, phBook_nameKey) << endl;
        }
    }

    return 0;
}

string request(string &command, map<string, string> &phBook_numKey, map<string, string> &phBook_nameKey)
{
    string str;
    if(isNum(command))
    {
       map<string, string>::iterator it = phBook_numKey.find(command);
       str = it->second;
    }else
    {
        map<string, string>::iterator it = phBook_nameKey.find(command);
        str = it->second;
    }
    return str;
}

void addPhone(string &command, map<string, string> &phBook_numKey, map<string, string> &phBook_nameKey)
{
    int space  = command.find(" ");
    string num = command.substr(0, space);
    string name = command.substr(space + 1, command.length());
    phBook_numKey.insert(make_pair(num, name));

    if(phBook_nameKey.find(name) == phBook_nameKey.end())
    {
        phBook_nameKey.insert(make_pair(name, num));
    }else
    {
        string str = phBook_nameKey.find(name)->second;
        str = str + " " + num;
        phBook_nameKey[name] = str;
    }
}

bool isNum(const string &command)
{
    int len = command.length();
    bool num = command[0] >= '0' && command[0] <= '9' && command[len - 1] >= '0' && command[len - 1] <= '9';
    int fl = 0;
    for(int i = 0; i < len; ++i)
    {
        if(command[i] == '-') ++fl;
        else fl = 0;
        if(!num || !((command[i] >= '0' && command[i] <= '9') || command[i] == '-') || fl > 1) return false;
    }
    return true;
}

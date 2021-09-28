#include <iostream>
#include <ctime>
#include <map>

using namespace std;

void begin(map<string, time_t> &, const string &, string &, time_t &);
time_t end(string &, const time_t &);
void status(const map<string, time_t> &, const string &);

int main()
{
    map<string, time_t> operations;
    time_t begin_time = 0;
    string command, current_operation;
    getline(cin, command);

    while(command != "exit")
    {
        if(command == "begin")
        {
            string operation_name;
            getline(cin, operation_name);
            begin(operations, operation_name, current_operation, begin_time);

        }else if(command == "end")
        {
            if(!current_operation.empty()){
                string tmp = current_operation;
                operations[tmp] += end(current_operation, begin_time);
            }

        }else if(command == "status")
        {
            status(operations, current_operation);
        }
        getline(cin, command);
    }

    return 0;
}

void begin(map<string, time_t> &op, const string &operation_name, string &current_oper, time_t &begin_time)
{

    if(op.find(operation_name) == op.end())
    {
        op.insert(make_pair(operation_name, 0));
        if(op.find(current_oper) != op.end())
        {
            string tmp = current_oper;
            op[tmp] += end(current_oper, begin_time);
        }
        current_oper = operation_name;
    }else
    {
        string tmp = current_oper;
        op[tmp] += end(current_oper, begin_time);
        current_oper = operation_name;
    }
    begin_time = time(nullptr);
}

time_t end(string &current_oper, const time_t &begin_time)
{
    current_oper.clear();
    return (time(nullptr) - begin_time);
}

void status(const map<string, time_t> &op, const string &current_oper)
{
    for(auto it = op.begin(); it != op.end(); ++it)
    {
        if(it->first != current_oper) cout << it->first << " : " << it->second << endl;
    }
    if(!current_oper.empty()) cout << current_oper << " : operation is in progress." << endl;
}

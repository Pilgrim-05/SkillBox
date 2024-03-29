#include <iostream>
#include <map>
#include <vector>
#include <initializer_list>
#include <cpr/cpr.h>

void GETRequest(const std::map<std::string, std::string>&);
void POSTRequest(const std::map<std::string, std::string>&);

using namespace std;

int main()
{
    map<string, string> args;
    string arg;
    getline(cin, arg);

    while(arg != "get" && arg != "post")
    {
        string value;
        getline(cin, value);
        args.insert(pair(arg, value));
        getline(cin, arg);
    }

    if(arg == "get")
    {
        GETRequest(args);
    }else if(arg == "post")
    {
        POSTRequest(args);
    }

    return 0;
}

void GETRequest(const map<string, string> &args)
{
    string serviceName = "http://httpbin.org/get?";

    for(auto it = args.begin(); it != args.end(); ++it)
        serviceName += it->first + "=" + it->second + "&";

    serviceName = serviceName.substr(0, serviceName.length()-1);
    auto responce = cpr::Get(cpr::Url(serviceName)).text;

    cout << responce << endl;
}

void POSTRequest(const map<string, string> &args)
{
    vector<cpr::Pair> pairs;
    for(auto it = args.begin(); it != args.end(); ++it)
    {
        cpr::Pair pair(it->first, it->second);
        pairs.push_back(pair);
    }

    auto responce = cpr::Post(cpr::Url("http://httpbin.org/post"),
                              cpr::Payload(pairs.begin(), pairs.end())).text;

    cout << responce << endl;
}

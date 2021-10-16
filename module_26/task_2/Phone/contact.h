#pragma once
#include <string>

class Contact
{
private:
    std::string name;
    std::string number;

public:
    Contact();
    bool setNum(const std::string &);
    void setName(const std::string &);
    std::string getNum();
    std::string getName();
};

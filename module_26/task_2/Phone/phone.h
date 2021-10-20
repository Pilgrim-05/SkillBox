#pragma once
#include "contact.h"
#include <map>

class Phone
{
private:
    std::map<std::string, std::string> contactNumber;
    bool isPhone(const std::string &);
public:
    Phone();
    void add();
    void call();
    void sms();
};


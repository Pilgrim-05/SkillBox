#pragma once
#include "contact.h"

class Phone
{
private:
    bool isPhone(const std::string &);
public:
    Phone();
    void add();
    void call();
    void sms();
};


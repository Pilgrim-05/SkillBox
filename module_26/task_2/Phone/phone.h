#pragma once
#include "contact.h"

class Phone
{
private:
    bool validNumber(const std::string &);

public:
    Phone();
    void add();
    void coll(const Contact &);
    void sms(const Contact &);
    std::string findContact(const std::string &);
};


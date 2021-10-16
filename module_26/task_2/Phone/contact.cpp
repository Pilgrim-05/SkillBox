#include "contact.h"

Contact::Contact(){}

bool Contact::setNum(const std::string &number)
{
    if(number.length() != 10) return false;
    for(int i = 0; i < number.length(); ++i)
    {
        if(number[i] < '0' || number[i] > '9') return false;
    }
    Contact::number = "+7";
    Contact::number += number;
    return true;
}

void Contact::setName(const std::string &name)
{
    Contact::name = name;
}

std::string Contact::getNum()
{
    return number;
}

std::string Contact::getName()
{
    return name;
}

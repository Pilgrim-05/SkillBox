#include "contact.h"



Contact::Contact(){}

void Contact::setNum(const std::string & number)
{
    Contact::number = number;
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

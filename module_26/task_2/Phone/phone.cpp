#include "phone.h"
#include <iostream>
#include <map>

std::map<std::string, std::string> contactNumber;
std::map<std::string, std::string> numberContact;

bool Phone::validNumber(const std::string &number)
{
    if(number.length() != 10) return false;
    for(int i = 0; i < number.length(); ++i)
    {
        if(number[i] < '0' || number[i] > 9) return false;
    }

    return true;
}

Phone::Phone()
{

}

void Phone::add()
{
    Contact contact;
    std::cout << "Enter contact name: ";
    std::string name;
    std::getline(std::cin, name);
    contact.setName(name);

    std::string number;
    std::cout << "Enter the contact number: +7 ";
    std::getline(std::cin, number);
    while(!Phone::validNumber(number)){
        std::cout << "Enter the correct number: +7 ";
        std::getline(std::cin, number);
    }
    contact.setNum(number);
    contactNumber.insert(std::make_pair(contact.getName(), contact.getNum()));
    numberContact.insert(std::make_pair(contact.getNum(), contact.getName()));
}

void Phone::coll(const Contact &contact)
{

}

void Phone::sms(const Contact &contact)
{

}

std::string Phone::findContact(const std::string &str)
{

}

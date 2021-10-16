#include "phone.h"
#include <iostream>
#include <map>

std::map<std::string, std::string> contactNumber;


Phone::Phone()
{

}

void Phone::add()
{
    Contact *contact = new Contact;
    std::cout << "Enter contact name: ";
    std::string name;
    getline(std::cin, name);
    contact->setName(name);

    std::string number;
    std::cout << "Enter the contact number: +7";
    getline(std::cin, number);
    while(!contact->setNum(number)){
        std::cout << "Enter the correct number: +7";
        getline(std::cin, number);
    }

    contactNumber.insert(std::make_pair(contact->getName(), contact->getNum()));

    delete contact;
}

void Phone::call()
{
    std::cout << "Enter contact name or phone number: ";
    std::string str;
    getline(std::cin, str);
    if(isPhone(str))
    {
        std::cout << "CALL " << str << std::endl;
    }else if(contactNumber.count(str))
    {
        std::cout << "CALL " << contactNumber.find(str)->second << std::endl;
    }else
    {
        std::cout << "There is no contact with this name." << std::endl;
    }
}

void Phone::sms()
{
    std::cout << "Enter contact name or phone number: ";
    std::string str;
    getline(std::cin, str);
    std::string msg;
    if(isPhone(str))
    {
        std::cout << "Enter your message: ";
        getline(std::cin, msg);
        std::cout << "The message was sent to the number: " << str << std::endl;
    }else if(contactNumber.count(str))
    {
        std::cout << "Enter your message: ";
        getline(std::cin, msg);
        std::cout << "The message was sent to the number: " << contactNumber.find(str)->second << std::endl;
    }else
    {
        std::cout << "There is no contact with this name." << std::endl;
    }
}

bool Phone::isPhone(const std::string &number)
{
    if(number.length() == 11)
    {
        if(number[0] != '8') {return false;}
        for(int i = 1; i < number.length(); ++i)
        {
            if(number[i] < '0' || number[i] > '9') return false;
        }
    }else if(number.length() == 12)
    {
        if(number[0] != '+') {return false;}

        for(int i = 1; i < number.length(); ++i)
        {
            if(number[i] < '0' || number[i] > '9') return false;
        }

    }else
    {
        return false;
    }

    return true;
}

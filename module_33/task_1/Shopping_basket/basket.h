#pragma once

#include <string>
#include <map>


class Basket
{
private:
    std::map<std::string, int> basket;
    std::map<std::string, int> storage;
    std::string storageFile;

    void show();

public:
    Basket(std::string fileStorage);

    void add(std::string article, int quantity);
    void remove(std::string article, int quantity);
};

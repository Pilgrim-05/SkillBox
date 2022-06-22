#include "basket.h"
#include <string>
#include <fstream>
#include <iostream>


Basket::Basket(std::string fileStorage)
{
    std::cout << "Basket: " << basket.size() << " Storage: " << storage.size() << std::endl;
    basket.clear();
    storage.clear();
    storageFile = fileStorage;
    std::ifstream file(storageFile);

    if(file.is_open())
    {
        while(!file.eof())
        {
            std::string article;
            int quantity;
            file >> article;
            file >> quantity;
            if(article != "")
                storage[article] = quantity;
        }

        file.close();
    }else
    {
        throw std::runtime_error("Warehouse not defined");
    }
}

void Basket::add(std::string article, int quantity)
{
    if(storage.find(article) == storage.end())
    {
        throw std::invalid_argument("Out of stock");
    }

    if(storage[article] < quantity || quantity <= 0)
    {
        throw std::invalid_argument("Invalid quantity");
    }

    basket[article] += quantity;
    storage[article] -= quantity;

    std::cout << std::endl << "*********Operation Add*********" << std::endl;
    show();
}

void Basket::remove(std::string article, int quantity)
{
    if(basket.find(article) == basket.end())
    {
        throw std::invalid_argument("No such product");
    }

    if(basket[article] < quantity || quantity <= 0)
    {
        throw std::invalid_argument("Invalid quantity");
    }

    basket[article] -= quantity;
    storage[article] += quantity;

    std::cout << std::endl << "*********Operation Remove*********" << std::endl;
    show();
}

void Basket::show()
{
    std::cout << std::endl << "*********Storage*********" << std::endl;
    for(auto it = storage.begin(); it != storage.end(); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }

    std::cout << std::endl << "*********Basket*********" << std::endl;

    for(auto it = basket.begin(); it != basket.end(); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }

}

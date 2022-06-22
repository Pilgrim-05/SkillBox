#include <iostream>
#include <fstream>
#include "basket.h"


void dbCreator(std::string dbFile);

int main()
{
    dbCreator("storage");

    try
    {
        Basket basket("storage");

        basket.add("#000001", 3);
        basket.remove("#000001", 2);
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(...)
    {
        std::cerr << "Another problem" << std::endl;
    }

    return 0;
}


void dbCreator(std::string dbFile)
{

    std::ofstream file(dbFile);
    std::map<std::string, int> db;
    db["#000001"] = 5;
    db["#000002"] = 7;
    db["#000123"] = 35;
    db["#002312"] = 10;
    db["#232234"] = 20;


    if(file.is_open())
    {
        for(auto it = db.begin(); it != db.end(); ++it)
        {
            file << it->first << " " << it->second << std::endl;
        }

        file.close();
    }
}

#include "disk.h"
#include <fstream>
#include <iostream>

void save(const std::vector<int> &vec)
{
    std::ofstream file(FILE_NAME);
    if(file.is_open())
    {
        for(int i: vec)
        {
            file << i << std::endl;
        }
        file.close();
    }else
    {
        std::cout << "File not found!";
    }
}


std::vector<int> load()
{
    std::vector<int> vec;
    std::ifstream file(FILE_NAME);
    if(file.is_open())
    {
        file.seekg (0, file.end);
        int length = file.tellg();
        file.seekg (0, file.beg);

        if(length != 0)
        {
            vec.resize(8);
            for(int i = 0; i < 8; ++i)
            {
                int tmp;
                file >> tmp;
                vec[i] = tmp;
            }
        }

        file.close();
    }else
    {
        std::cout << "File not found!";
    }

    return vec;
}

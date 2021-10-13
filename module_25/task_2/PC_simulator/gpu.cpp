#include "gpu.h"
#include <iostream>

void display(const std::vector<int> &vec)
{
    if(vec.empty())
    {
        std::cout << "**** RAM is empty ****";
    }else
    {
        for(auto i : vec)
        {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

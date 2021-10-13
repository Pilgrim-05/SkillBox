#include "kbd.h"
#include <iostream>

std::vector<int> input()
{
    std::vector<int> vec(8);
    for(int i = 0; i < vec.size(); ++i)
    {
         std::cin >> vec[i];
    }
    std::cin.ignore(32767, '\n');
    return vec;
}

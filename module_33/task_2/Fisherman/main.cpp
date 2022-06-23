#include <iostream>
#include <ctime>
#include "field.h"


int main()
{
    Field fields[9];
    std::srand(std::time(nullptr));

    fields[std::rand() % 9] = Content::FISH;

    for(int i = 3; i > 0;)
    {
        int tmp = std::rand() % 9;
        if(fields[tmp].get() == Content::FREE)
        {
            fields[tmp] = Content::BOOT;
            --i;
        }
    }
    int counter = 0;
    int fish_rod;
    bool flag = true;
    while(flag)
    {
        std::cout << "Enter a number 0...8: ";
        std::cin >> fish_rod;
        fish_rod %= 9;
        try {
            fields[fish_rod].fishing();
        }  catch (const Fortune& e) {
            flag = false;
            std::cerr << e.what() << " Number of attempts: " << counter << std::endl;
        } catch(const Failure& e) {
            flag = false;
            std::cerr << e.what() << std::endl;
        }

        ++counter;
    }

    return 0;
}

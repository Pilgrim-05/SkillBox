#include "register.h"


template<typename KEY, typename VAL>
void Register<KEY, VAL>::add()
{
    std::cout << "Enter key: ";
    KEY key;
    std::cin >> key;

    std::cout << "Enter value: ";
    VAL value;
    std::cin >> value;

    registers.insert(std::make_pair(key, value));
}

template<typename KEY, typename VAL>
void Register<KEY, VAL>::remove()
{
    std::cout << "Enter key: ";
    KEY key;
    std::cin >> key;

    if(registers.find(key) != registers.end())
    {
        registers.erase(key);
    }else
    {
        std::cout << "There is no entry with this key in the registry." << std::endl;
    }
}

template<typename KEY, typename VAL>
void Register<KEY, VAL>::print()
{
    for(auto at : registers)
    {
        std::cout << at.key() << "\t:\t" << at.value() << std::endl;
    }
}

template<typename KEY, typename VAL>
void Register<KEY, VAL>::find()
{
    std::cout << "Enter key: ";
    KEY key;
    std::cin >> key;

    auto ret = registers.equal_range(key);

    std::cout << key << " =>";
    for (auto it=ret.first; it!=ret.second; ++it)
      std::cout << ' ' << it->second;
    std::cout << '\n';

}




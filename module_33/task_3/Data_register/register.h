#pragma once
#include <iostream>
#include <map>


template<typename KEY, typename VAL>
class Register
{
private:
    std::multimap<KEY, VAL> registers;

public:
    void add();
    void remove();
    void print();
    void find();
};


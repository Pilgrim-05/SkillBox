#include "cpu.h"

int compute(const std::vector<int> &vec)
{
    int summ = 0;
    for(int i : vec)
        summ += i;
    return summ;
}

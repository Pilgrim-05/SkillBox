#include <iostream>
#include <vector>
#include <exception>

template<typename T>
T average(const std::vector<T> &arr)
{
    T result = 0;
    if(arr.size())
    {
        for(auto at : arr)
            result +=at;
        result /=arr.size();
    }else
    {
        throw std::runtime_error("Divide by zero!");
    }

    return result;
}

template<typename T>
void inputArray(std::vector<T> &arr)
{
    T tmp;
    for(int i = 0; i < arr.size(); ++i)
    {
        std::cin >> tmp;
        arr[i] = tmp;
    }
}


int main()
{
    std::vector<int> iArr(5);
    std::vector<double> dArr(5);

    inputArray(iArr);
    std::cout << "Integer Average: " << average(iArr) << std::endl;

    inputArray(dArr);
    std::cout << "Double Average: " << average(dArr) << std::endl;


    return 0;
}




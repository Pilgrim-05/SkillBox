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
        throw std::runtime_error("ERROR! Divide by zero!");
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
    std::vector<int> iArr(0);
    std::vector<double> dArr(5);

    inputArray(iArr);
    try {
        std::cout << average(iArr) << std::endl;
    }  catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }


    inputArray(dArr);
    try {
        std::cout << average(dArr) << std::endl;
    }  catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }



    return 0;
}




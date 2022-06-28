#include <iostream>
#include <array>

int main() {
    std::array<int, 5> arr{1, 2, 3, 4, 5};

    for(auto at : arr)
        std::cout << at << " ";
    std::cout << std::endl;
}

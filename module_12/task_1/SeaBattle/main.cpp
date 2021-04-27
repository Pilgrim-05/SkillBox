#include <iostream>

using namespace std;
int main() {

    std::cout << "\n~~~~~ SEA BATTLE ~~~~~\n\n";
    std::cout << "size of boats:\n\n";

    bool tiny[] = {1};
    bool small[] = {1, 1};
    bool medium[] = {1, 1, 1};
    bool large[] = {1, 1, 1, 1};

    cout << "tiny - " << sizeof(tiny)/sizeof(tiny[0]) << endl;
    cout << "small - " << sizeof(small)/sizeof(small[0]) << endl;
    cout << "medium - " << sizeof(medium)/sizeof(medium[0]) << endl;
    cout << "large - " << sizeof(large)/sizeof(large[0]) << endl;
}

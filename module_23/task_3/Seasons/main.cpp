#include <iostream>

#define SPRING 1
#define SUMMER 2
#define AUTUMN 3
#define WINTER 4

#define TMP AUTUMN

using namespace std;

int main() {

    #if TMP==SPRING
        cout << "SPRING";
    #elif TMP==SUMMER
        cout << "SUMMER";
    #elif TMP==AUTUMN
        cout << "AUTUMN";
    #elif TMP==WINTER
        cout << "WINTER";
    #endif

    return 0;
}

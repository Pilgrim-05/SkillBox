#include <iostream>

using std::cout;
using std::endl;

int* reversArray(int*, int);
void printArray(int* arr, int size);

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printArray(arr, 10);
    int *revAr = reversArray(arr, 10);
    printArray(revAr, 10);

    cout << endl << "Array address = \t" << arr << endl;
    cout << "Revers Array address = \t" << revAr << endl;

    delete[] revAr;
    return 0;
}

int* reversArray(int* arr, int size){
    int *rev = new int[size];
    for(int i = 0;i < size; ++i){
        *(rev + i) = *(arr + (size - 1 - i));
    }
    return rev;
}
void printArray(int* arr, int size){
    for(int i = 0;i < size; ++i){
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

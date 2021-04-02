#include <iostream>
#include <vector>

using std::cout;
using std::endl;

void swapVec(std::vector<int>& vec, int *arr);

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    swapVec(vec, array);

    int size = vec.size();

    cout << "vec =   ";
    for(int i = 0; i < size; ++i)
        cout << vec.at(i) << " ";
    cout << endl;

    cout << "array = ";
    for(int i = 0; i < size; ++i)
        cout << array[i] << " ";
    cout << endl;

    return 0;
}

void swapVec(std::vector<int>& vec, int *arr){
    int tmp;
    for(size_t i = 0; i < vec.size(); ++i){
        tmp = vec.at(i);
        vec.at(i) = arr[i];
        arr[i] = tmp;
    }
}


#include <iostream>

using namespace std;

void swap(int* num1, int* num2){
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

int main()
{
    int a = 10;
    int b = 20;
    swap(&a, &b);
    cout << "a = " << a << endl << "b = " << b << endl;
    return 0;
}


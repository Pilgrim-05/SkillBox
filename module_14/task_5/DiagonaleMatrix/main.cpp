#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void matrixFill(float arr[][4], int);
void printMatrix(float arr[][4], int size);

int main()
{
    float matrixM[4][4];
    matrixFill(matrixM, 4);
    printMatrix(matrixM, 4);
    return 0;
}

void matrixFill(float arr[][4], int size){

    for(int i =0; i < size; i++){
        for (int j = 0; j < size; j++)
        {
            cin >> arr[i][j];
        }
    }
}

void printMatrix(float arr[][4], int size){

    for(int i =0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] *= (i == j);
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

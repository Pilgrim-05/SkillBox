#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void matrixFill(float arr[][4], int);
void diagonalMatrixs(float arr[][4], int size);
void printMatrix(float arr[][4], int size);

int main()
{
    float matrixM[4][4];

    matrixFill(matrixM, 4);
    diagonalMatrixs(matrixM, 4);
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

void diagonalMatrixs(float arr[][4], int size){
    for(int i =0; i < size; i++){
        for (int j = 0; j < size; j++)
        {
            if(i != j)arr[i][j] = 0.0;
        }
    }
}

void printMatrix(float arr[][4], int size){

    for(int i =0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void matrixFill(int arr[][4], int);
bool EqualMatrixs(int arrA[][4], int arrB[][4], int size);
void printMatrix(int arr[][4], int size);

int main()
{
    int matrixA[4][4];
    int matrixB[4][4];

    if(EqualMatrixs(matrixA, matrixB, 4)){
        cout << "matrix A is equal to matrix B" << endl;
        printMatrix(matrixB, 4);
    }else{
        cout << "matrix A is not equal to matrix B" << endl;
    }
    return 0;
}

void matrixFill(int arr[][4], int size){

    for(int i =0; i < size; i++){
        for (int j = 0; j < size; j++)
        {
            cin >> arr[i][j];
        }
    }
}

bool EqualMatrixs(int arrA[][4], int arrB[][4], int size){
    cout << "Enter matrix A:" << endl;
    matrixFill(arrA, 4);
    cout << "Enter matrix B:" << endl;
    for(int i =0; i < size; i++){
        for (int j = 0; j < size; j++)
        {
            cin >> arrB[i][j];
            if(arrB[i][j] != arrA[i][j]) return false;
        }
    }

    return true;
}

void printMatrix(int arr[][4], int size){

    for(int i =0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}



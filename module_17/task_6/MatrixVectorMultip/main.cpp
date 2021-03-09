#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void matrixFill(float arr[][4], int);
void multip(float arr1[][4], float arr2[][4], float arr3[][4], int size);
void printMatrix(float arr[][4], int size);

int main()
{    
    float matrixM[4][4];
    float vector[1][4];
    float vectorResult[1][4];

    matrixFill(matrixM, 4);
    matrixFill(vector, 1);
    multip(matrixM, vector, vectorResult, 4);
    cout << endl << "result of Multiplication" << endl;
    printMatrix(vectorResult, 1);

    return 0;
}

void matrixFill(float arr[][4], int size){
    int columnsCount = sizeof(arr[0])/ sizeof(arr[0][0]);
    cout << "Pleace, enter matrix " << size << "x" << columnsCount << endl;
    for(int i =0; i < size; i++){
        for (int j = 0; j < columnsCount; j++)
        {
            cin >> arr[i][j];
        }
    }
}

void multip(float arr1[][4], float arr2[][4], float arr3[][4], int size){

    for(int i =0; i < size; i++){
        int summ = 0;
        for (int j = 0; j < size; j++)
        {
         summ +=  arr1[i][j] * arr2[0][j];
        }
        arr3[0][i] = summ;
    }
}

void printMatrix(float arr[][4], int size){
    int columnsCount = sizeof(arr[0])/ sizeof(arr[0][0]);
    for(int i =0; i < size; i++)
    {
        for (int j = 0; j < columnsCount; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


#include <iostream>

using namespace std;

void printArray(char arr[][3], int rowsCount);

int main()
{
    cout << "TicTacToe v.2.0" << endl;

    char field[3][3] = {{' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '}};





    int rowsNum = sizeof(field) / sizeof(field[0]);
    printArray(field, rowsNum);

    return 0;
}

void printArray(char arr[][3], int rowsCount){

    int columnsCount = sizeof(arr[0])/ sizeof(arr[0][0]);
    for(int i =0; i < rowsCount; i++)
    {
        for (int j = 0; j < columnsCount; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

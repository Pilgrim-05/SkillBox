#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const int SIZE = 12;

void initBumps(bool arr[][SIZE], int size);
bool print(bool arr[][SIZE], int size);
void bursting(bool arr[][SIZE], int size, int startX, int startY, int endX, int endY);


int main()
{
    int startX, startY, endX, endY;
    bool bumps[SIZE][SIZE];

    initBumps(bumps, SIZE);

    while(print(bumps, SIZE)){
        cout << endl << "start coordinates: ";
        cin >> startX >> startY;
        cout << endl << "end coordinates: ";
        cin >> endX >> endY;
        bursting(bumps, SIZE, startX, startY, endX, endY);
    }

    cout << endl << "****FINISH!****" << endl;

    return 0;
}

void bursting(bool arr[][SIZE], int size, int startX, int startY, int endX, int endY){

    if(size > startX && size > startY && size > endX && size > endY
            && 0 <= startX && 0 <= startY && 0 <= endX && 0 <= endY
            && startX <= endX && startY <= endY){
        for(int i = startX; i <= endX; ++i){
            for(int j = startY; j <= endY; ++j){
                if(arr[i][j]) cout << "Pop!" << endl;
                arr[i][j] = false;
            }
        }
    }else{
        cout << "Incorrect input date!" << endl;
    }

}

void initBumps(bool arr[][SIZE], int size){
    int colNum = sizeof(arr[0]) / sizeof(arr[0][0]);
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < colNum; ++j){
            arr[i][j] = true;
        }
    }
}

bool print(bool arr[][SIZE], int size){
    int colNum = sizeof(arr[0]) / sizeof(arr[0][0]);
    bool result = false;
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < colNum; ++j){
            if(arr[i][j]){
                cout << "o ";
                result = true;
            }else{
                cout << "x ";
            }
        }
        cout << endl;
    }
    return result;
}

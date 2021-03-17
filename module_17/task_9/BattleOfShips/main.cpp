#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

const int SIZE = 10;

void printField(int field[][SIZE], int rows);
void rankingShips(int field[][SIZE]);
int shot(int row, int col, int field[][SIZE]);
void gamePlayer(int field1[][SIZE], int field2[][SIZE]);

int main()
{
    int fieldPlayer1[SIZE][SIZE]{0};
    int fieldPlayer2[SIZE][SIZE]{0};

    cout << "Player 1 fill in the field:" << endl;
    rankingShips(fieldPlayer1);
    cout << endl << "Player 2 fill in the field:" << endl;
    rankingShips(fieldPlayer2);

//    cout << endl << "Player 1 field:" << endl;
//    printField(fieldPlayer1, SIZE);
//    cout << endl << "Player 2 field:" << endl;
//    printField(fieldPlayer2, SIZE);

    gamePlayer(fieldPlayer1, fieldPlayer2);

    return 0;
}

void gamePlayer(int field1[][SIZE], int field2[][SIZE]){
    int shipsPlayer1 = 20;
    int shipsPlayer2 = 20;
    int player = 1;
    int counter = 0;

    int size = sizeof(field1[0])/sizeof(field1[0][0]);

    while(shipsPlayer1 && shipsPlayer2){
        int row, col;
        cout << "Player " << player << ", enter coordinates for the shot: ";
        cin >> row >> col;
        while(row < 0 || row > 9 || col < 0 || col > 9){
            cout << "wrong coordinates.\nre-enter coordinates: ";
            cin >> row >> col;
        }

        if(counter % 2 == 0){
            shipsPlayer2 -= shot(row, col, field2);
            player = 2;
            printField(field2, size);
        }else{
            shipsPlayer1 -= shot(row, col, field1);
            player = 1;
            printField(field1, size);
        }
        ++counter;
    }
    player = player == 1 ? 2 : 1;

    cout << "******** Won by Player " << player << " ********" << endl;
}

int shot(int row, int col, int field[][SIZE]){
    int result = 0;
    if(field[row][col] == 1){
        cout << "Hit the target!" << endl;
        field[row][col] = 3;
        result = 1;
    }else{
        cout << "Off target!" << endl;
    }
    return result;
}

void rankingShips(int field[][SIZE]){
    int count = 4;
    int ship = 1;
    int row, col;
    string position = "H";

    for(int k = 0; k < 4; ++k){
        cout << "a ship with a size - " << ship << endl;

        for(int i = 0; i < count; ++i){
            bool flag;
            do{
                flag = false;
                cout << "Enter start coordinates: ";
                cin >> row >> col;
                if(ship > 1){
                    cout << "Enter position horizontal or vertical (H/V): ";
                    cin >> position;
                }

                if(position == "V" || position == "H"){
                    for(int l = 0; l < ship; ++l){
                        if(position == "H"){
                            if(row < 0 || row > SIZE-1 || col < 0
                                    || col + ship > SIZE || field[row][col + l] != 0){
                                flag = true;
                                break;
                            };
                        }else if(position == "V"){
                            if(row < 0 || row + ship > SIZE || col < 0
                                    || col > SIZE-1 || field[row + l][col] != 0){
                                flag = true;
                                break;
                            };
                        }
                    }
                }else {
                    flag = true;
                }
                if(flag) cout << "Something went wrong, please try again." << endl;
            }while(flag);

            for(int j = 0; j < ship; ++j){
                if(position == "H"){
                    field[row][col + j] = 1;
                    if(row - 1 > 0)field[row - 1][col + j] = 2;
                    if(row + 1 < 10)field[row + 1][col + j] = 2;
                    if(col - 1 > 0 && j == 0)field[row][col - 1] = 2;
                    if(col + ship + 1 < 10 && j == 0)field[row][col + ship] = 2;
                }else if(position == "V"){
                    field[row + j][col] = 1;
                    if(col - 1 > 0)field[row + j][col - 1] = 2;
                    if(col + 1 < 10)field[row + j][col + 1] = 2;
                    if(row - 1 > 0 && j == 0)field[row - 1][col] = 2;
                    if(row + ship + 1 < 10 && j == 0)field[row + ship][col] = 2;
                }
            }
            printField(field, SIZE);
        }
        ++ship;
        --count;
    }
    cout << endl;
}

void printField(int field[][SIZE], int rows){
    int columns = sizeof(field[0]) / sizeof(field[0][0]);
    cout << endl;
    for(int i =0; i < rows; ++i){
        for(int j =0; j < columns; ++j){
            if(field[i][j] == 1) cout << "X" << " ";
            else if(field[i][j] == 3) cout << "*" << " ";
            else cout << "." << " ";
            //cout << field[i][j] << " ";
        }
        cout << endl;
    }
}

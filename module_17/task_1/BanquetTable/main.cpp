#include <iostream>

using namespace std;

int main()
{
    int personsArray[2][6] = {{8, 6, 6, 6, 6, 6},
                              {8, 6, 6, 6, 6, 6}};

    personsArray[0][4] +=1;
    personsArray[1][0] -=2;

    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 6; ++j){
            cout << personsArray[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


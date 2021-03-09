#include <iostream>

using namespace std;

int main()
{
    int matrix[5][5];
    int val = 0;
    int delta = 1;
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            matrix[i][j] = val;
            cout << matrix[i][j] << " ";
            val += delta;
        }
        val += 5 - delta;
        delta = -delta;
        cout << endl;
    }
    return 0;
}


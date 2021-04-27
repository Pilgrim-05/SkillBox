#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

enum notes{
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SO = 16,
    LA = 32,
    SI = 64
};
void inputNumber(string &combination);
void piano(const string &str);

int main()
{
    string combination;
    string melody = "";
    for(int i = 0; i < 12; ++i){
        inputNumber(combination);
        melody +=combination;
    }
    piano(melody);

    return 0;
}

void inputNumber(string &str){
    bool res;
    do{
        res = false;
        cin >> str;
        for(size_t i = 0; i < str.length(); ++i){
            if(str[i] < '1' || str[i] > '7'){
                res = true;
                break;
            }
        }
        if(res) cout << "WARNING: invalid combination input!" << endl;
    }while(res);
}

void piano(const string &str){
    int note;
    for(size_t i = 0; i < str.length(); ++i){
        note = str[i] - '0' - 1;

        switch (1 << note) {
        case DO:
            cout << "Do ";
            break;
        case RE:
            cout << "Re ";
            break;
        case MI:
            cout << "Mi ";
            break;
        case FA:
            cout << "Fa ";
            break;
        case SO:
            cout << "So ";
            break;
        case LA:
            cout << "La ";
            break;
        case SI:
            cout << "Si ";
            break;
        }
    }
    cout << endl;
}

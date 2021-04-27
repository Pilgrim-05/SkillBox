#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void showGamesField(string str);
string outcome(string str);
string fillingField();
bool validator(string str);

int main()
{
	cout << "Please fill in the playing field:\n";
    string field;
    field = fillingField();
    showGamesField(field);
    cout << endl << outcome(field) << endl;

    return 0;
}

string outcome(string str){
    int wonCount = 0;
    string result;
    char ch = 0;
    if(str[0] != '.' && str[0] == str[4] && str[0] == str[8]){
        ch = str[0];
        wonCount++;
    }
    if(str[2] != '.' && str[2] == str[4] && str[2] == str[6]){
        ch = str[2];
        if(wonCount == 0) wonCount++;
    }
    for(int k = 0; k < 9; k +=3){
        if(str[k] != '.' && str[k] == str[k + 1] && str[k] == str[k + 2]){
            ch = str[k];
            wonCount++;
        }
    }
    for(int i = 0; i < 3; i++){
        if(str[i] != '.' && str[i] == str[i + 3] && str[i] == str[i + 6] ){
            if(ch != str[i]){
                ch = str[i];
                wonCount++;
            }
        }
    }

    if(!validator(str) || wonCount > 1)result = "Incorrect.";
    else if(wonCount == 1) result = (ch == 'X' ? "Petya won" : "Vanya won");
    else result = "Nobody";

    return result;
}

string fillingField(){
    string str;
    int count = 9;
    char ch;
    do{
        cin >> ch;
        if(ch == 'X' || ch == 'O' || ch == '.'){
            str += ch;
            count--;
        }else{
            cout << "Invalid character, enter character 'X', 'O' or '.'\n";
        }

    }while(count);

    return str;
}

bool validator(string str){
    bool result = false;
    int countX = 0;
    int countO = 0;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == 'X') countX++;
        if(str[i] == 'O') countO++;
    }

    if(countO == countX || countO == countX-1) result = true;

    return result;
}

void showGamesField(string str){
  for(int i = 0; i < 9; i++){
    if(i % 3 == 0) cout << endl;
    cout << str[i];
  }
  cout << endl;
}

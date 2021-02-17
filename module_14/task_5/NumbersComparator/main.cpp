#include <iostream>

using namespace std;

int indexDot(string str);
bool signCheck(string str);
string subStr(string str, int begin, int end);
string zeroRemov(string str);
bool isValidRealNum(string str);
string compare(string str1, string str2);

int main()
{
    string realNum1;
    string realNum2;

    do{
        cin.clear();
        cout << "Enter two real numbers" << endl;
        cin >> realNum1;
        cin >> realNum2;
    }while(!(isValidRealNum(realNum1) && isValidRealNum(realNum2)));

    cout << realNum1 << endl << realNum2 << endl << endl;

    cout << compare(realNum1, realNum2);

    return 0;
}

string compare(string str1, string str2){
    // str1 < str2 Less
    // str1 > str2 More
    // str1 == str2 Equal
    str1 = zeroRemov(str1);
    str2 = zeroRemov(str2);
    if(str1 == str2) return "Equal";
    if(signCheck(str1) && !signCheck(str2))return "Less";
    if(!signCheck(str1) && signCheck(str2))return "More";

    if(!signCheck(str1) && !signCheck(str2)){
        string preDotStr1 = subStr(str1, 0, indexDot(str1));
        string preDotStr2 = subStr(str2, 0, indexDot(str2));



    }

    return "error";
}

string subStr(string str, int begin, int end){
    string tmpStr;
    for(int i = begin; i < end; i++){
        tmpStr += str[i];
    }
    return tmpStr;
}

bool signCheck(string str){
    return (str[0] == '-'?true:false);
}

bool isValidRealNum(string str){
    int dot = 0;
    bool isNumber = false;
    bool isValid = true;

    for(int i = 0; i < str.length() && isValid; i++){
      if(str[i] >= '0' && str[i] <= '9'){
        isNumber = true;
      }else if((str[i] == '-' && i != 0) || (str[i] == '.' && dot > 0)
          || (!(str[i] >= '0' && str[i] <= '9') && str[i] != '.'
          && str[i] != '-')){
        isValid = false;
      }else if(str[i] == '.' && dot == 0){
        dot++;
      }
    }
    return ((isValid && isNumber))? true : false;
}

string zeroRemov(string str){
    int begin;
    string tmpStr;
    if(str[0] == '-'){ begin = 1; tmpStr += '-';}
    else{ begin = 0;}

    int dot = indexDot(str);
    bool flag = true;
    for(int i = begin; i < dot; i++){
        if(flag && str[i] == '0'){
            continue;
        }else{
            flag = false;
            tmpStr += str[i];
        }
    }
    int index = str.length()-1;
    for(int i = str.length()-1; i >= dot; i--){
        if(str[i] != '0'){
            index = i;
            break;
        }
    }
    if(index != dot){
       for(int i = dot; i <= index; i++){
           tmpStr += str[i];
       }
    }

    return tmpStr;
}

int indexDot(string str){
    int result = str.length();
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '.') return i;
    }
    return result;
}

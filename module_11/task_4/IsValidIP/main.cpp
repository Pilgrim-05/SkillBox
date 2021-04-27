#include <iostream>

using namespace std;

bool checkChars(string str);
string subStr(string str, int begin, int end);
bool partCheck(string str);
bool checkIp(string str);
int indexChar(string str, char ch);

int main()
{
    cout << "Enter the IP address: ";
    string ip;
    cin >> ip;


    cout << endl << (checkIp(ip)?"Yes":"No") << endl;

    return 0;
}

bool checkIp(string str){
    if(!checkChars(str)) return false;
    str += '.';
    for(int i = 0; i < 4; i++){
        if(!partCheck(subStr(str, 0, indexChar(str, '.')))) return false;
        str = subStr(str, indexChar(str, '.')+1, str.length());
    }
    return true;
}

bool partCheck(string str){
    if(str.length() > 3) return false;
    if(str.length() > 1 && str[0] == '0') return false;
    if(stoi(str) > 255 || stoi(str) < 0) return false;

    return true;
}

string subStr(string str, int begin, int end){
    string tmpStr;
    for(int i = begin; i < end; i++){
        tmpStr += str[i];
    }
    return tmpStr;
}

bool checkChars(string str){
    int countDot = 0;
    bool flag = false;
    if(str[0] == '.' || str[str.length()-1] == '.')return false;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '.'){
            countDot++;
            if(flag) return false;
            flag = true;
        }else if(str[i] < '0' || str[i] > '9'){
            return false;
        }else{
            flag = false;
        }
    }
    return (countDot == 3? true: false);
}

int indexChar(string str, char ch){
    int result = -1;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ch) return i;
    }
    return result;
}

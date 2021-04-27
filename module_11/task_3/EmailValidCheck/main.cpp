#include <iostream>

using namespace std;

bool checkDotAndAt(string str);
bool checkChar(char ch);
bool checkSpecChars(char ch);
int indexChar(string str, char ch);
string getSubStr(string str, int begin, int end);
bool beforeAt(string str);
bool afterAt(string str);
bool isValidEmail(string str);


int main()
{
    cout << "Enter your email: ";
    string email;
    cin >> email;
    cin.ignore(32767,'\n');

    cout << (isValidEmail(email)?"Yes":"No");

    return 0;
}


bool isValidEmail(string str){

   bool result = false;
   if(!checkDotAndAt(str)) return result;

   if(beforeAt(getSubStr(str, 0, indexChar(str, '@')))
      && afterAt(getSubStr(str, indexChar(str, '@') +1, str.length()))){
    result = true;
   }
   return result;
}

bool beforeAt(string str){
  if(str.length() > 64 || str.length() < 1) return false;
  for(int i = 0; i < str.length(); i++){
    if(!(checkChar(str[i]) || checkSpecChars(str[i]))) return false;
  }
  return true;
}

bool afterAt(string str){
  if(str.length() > 63 || str.length() < 1) return false;
  for(int i = 0; i < str.length(); i++){
    if(!checkChar(str[i])) return false;
  }
  return true;
}

string getSubStr(string str, int begin, int end){
    string result;
    for(int i = begin; i < end; i++){
        result += str[i];
    }
    return result;
}

bool checkSpecChars(char ch){
    string allowedChar = "!#$%&'*+-/=?^_`{|}~";
    for(unsigned  int i = 0; i < allowedChar.length(); i++){
        if(allowedChar[i] == ch) return true;
    }
    return false;
}

bool checkChar(char ch){
    bool result = false;
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')|| (ch >= '0' && ch <= '9') || ch == '.' || ch == '-'){
        result = true;
    }
    return result;
}

bool checkDotAndAt(string str){
    if(str[0] == '.' || str[str.length()-1] == '.') {return false;}
    if(str[0] == '@' || str[str.length()-1] == '@') {return false;}
    bool statusDot = true;
    bool statusAt = false;
    for(unsigned int i = 1; i < str.length()-1; i++){
        if(str[i] == '.'){
            if(!statusDot){return false;}
            statusDot = false;
        }else {
            statusDot = true;
        }
        if(str[i] == '@'){
            if(statusAt){return false;}
            statusAt = true;
        }
    }
    return statusAt;
}

int indexChar(string str, char ch){
    int index = -1;
    for(unsigned int i = 0; i < str.length(); i++){
        if(str[i] == ch){
            index = i;
            return index;
        }
    }
    return index;
}

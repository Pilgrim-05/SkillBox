#include <iostream>

using std::cout;
using std::endl;

bool subStr(const char*, const char*);

int main()
{
    char* str = "Hello world";
    char* str1 = "wor";
    char* str2 = "banana";

    cout << (subStr(str, str1) ? "true" : "false") << endl;
    cout << (subStr(str1, str2) ? "true" : "false") << endl;

    return 0;
}

bool subStr(const char* str1, const char* str2){
    if(!*str1 || !*str2) return false;

    for(int i = 0;*(str1 + i); ++i){
        int j = 0;
        if(str1[i] == str2[j]){
            for(j = 1;*(str1 + j);++j){

            }
        }
    }


}


#include <iostream>

using std::cout;
using std::endl;

bool subStr(const char*, const char*);

int main()
{
    const char* str = "Hello world";
    const char* str1 = "wor";
    const char* str2 = "banana";

    cout << (subStr(str, str1) ? "true" : "false") << endl;
    cout << (subStr(str, str2) ? "true" : "false") << endl;

    return 0;
}

bool subStr(const char* str1, const char* str2){
    if(!*str1 || !*str2) return false;
    bool res = false;
    for(int i = 0;*(str1 + i); ++i){         
        if(str1[i] == str2[0]){
            res = true;
            for(int j = 1;*(str2 + j);++j){
                if(str2[j] != str1[i + j]){
                    res = false;
                    break;
                }
            }
        }
        if(res)break;
    }
    return res;
}

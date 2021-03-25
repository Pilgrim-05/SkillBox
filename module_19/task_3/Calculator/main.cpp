#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int operation(const string &str);

int main()
{
    string str;
    cin >> str;

    string num1 = str.substr(0,operation(str));
    string num2 = str.substr(operation(str)+1, str.length() - operation(str));

    double result = 0.0;

    if(str[operation(str)] == '+'){
        result = std::stod(num1) + std::stod(num2);
    }else if(str[operation(str)] == '-'){
        result = std::stod(num1) - std::stod(num2);
    }else if(str[operation(str)] == '*'){
        result = std::stod(num1) * std::stod(num2);
    }else if(str[operation(str)] == '/'){
        result = std::stod(num1) / std::stod(num2);
    }

    cout << result << endl;
    return 0;
}

int operation(const string &str){
    int res = -1;
    for(int i = 0; i < str.length(); ++i){
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
            res = i;
            break;
        }
    }
    return res;
}


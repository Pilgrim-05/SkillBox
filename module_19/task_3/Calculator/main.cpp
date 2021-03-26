#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int operation(const string &str);
bool isExpression(const string &str);

int main()
{
    string str;
    cin >> str;

    if(operation(str) != -1 && isExpression(str)){
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
    }else{
        cout << "WARNING: Invalid expression!" << endl;
    }
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

bool isExpression(const string &str){
    bool op;
    for(size_t i = 0; i < str.length(); ++i){
        op = (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '.');
        if(!((str[i] >= '0' && str[i] <= '9') || op)){
            return false;
            break;
        }
    }
    return true;
}

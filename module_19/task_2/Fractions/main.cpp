#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

void inputNumber(string &var, string comment);

int main()
{
    string numerator;
    string denominator;
    inputNumber(numerator, "Please enter the numerator: ");
    inputNumber(denominator, "Please enter the denominator: ");
    string result = numerator + "." + denominator;
    double number = stod(result);
    cout << number << endl;
    return 0;
}
void inputNumber(string &var, string comment){
    bool res;
    do{
        res = false;
        cout << comment;
        cin >> var;
        for(size_t i = 0; i < var.length(); ++i){
            if(var[i] < '0' || var[i] > '9'){
                res = true;
                break;
            }
        }
        if(res) cout << "WARNING: wrong number input!" << endl;
    }while(res);
}

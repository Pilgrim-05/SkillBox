#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool is_date(string $date);

int main()
{
    std::ofstream fout("../src/report.txt", std::ios::app);
    string name;
    string surname;
    string date;
    double salary;

    if(fout.is_open()){
        cout << "Name: ";
        cin >> name;
        cout << "Surname: ";
        cin >> surname;
        cout << "DATE (dd.mm.yyyy): ";
        cin >> date;
        while(!is_date(date)){
            cout << "Date is incorrect." << endl;
            cout << "DATE (dd.mm.yyyy): ";
            cin >> date;
        }
        cout << "Salary: ";
        cin >> salary;
        fout << name << " " << surname << " " << date << " " << salary <<endl;

        fout.close();
    }else{
        cout << "This file cannot be opened." << endl;
    }

    return 0;
}

bool is_date(string date){
    int day = std::stoi(date.substr(0, 2));
    int month = std::stoi(date.substr(3, 2));
    int year = std::stoi(date.substr(6));
    if(day > 0 && day <= 31 && month > 0 && month <= 12 && year > 0 && year <= 9999) return true;
    else return false;
}


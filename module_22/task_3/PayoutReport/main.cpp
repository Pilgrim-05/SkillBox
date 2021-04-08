#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    std::ifstream iFile("../src/payout.txt");
    double summ = 0;
    double max = 0;
    string fullname;
    if(iFile.is_open()){

        while(!iFile.eof()){
            string name, fname, date;
            double many;

            iFile >> name >> fname;
            iFile >> many;
            iFile >> date;

            cout << name << " " << fname << " " << many << " " << date << endl << endl;
            summ +=many;
            if(many > max){
                fullname = "";
                max = many;
                fullname = name + " " + fname;
            }

        }
    }else {
        cout << "File not found!";
    }

    cout << "Funds paid out - " << summ << endl;
    cout << fullname << " has a maximum salary." << endl;
    return 0;
}


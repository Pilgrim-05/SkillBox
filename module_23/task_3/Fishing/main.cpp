#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    std::ifstream fin("../src/river.txt");
    std::ofstream fout("../src/basket.txt", std::ios::app);

    if(!fout.is_open()) cout << "You forgot basket." << endl;
    else if(!fin.is_open())cout << "river not found." << endl;
    else{
        string fish;
        cout << "Fish type: ";
        cin >> fish;
        int counter = 0;
        while(!fin.eof()){
            string tmp;
            fin >> tmp;
            if(tmp == fish){
               fout << fish << endl;
               ++counter;
            }
        }
        cout << "amount of catch: " << counter << endl;
    }
    fin.close();
    fout.close();

    return 0;
}

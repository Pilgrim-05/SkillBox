#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    char* fileName;
    cout << "Enter file name: ";
    cin >> fileName;
    std::ifstream words;

    words.open(fileName);
    if(words.is_open()){
        while(!words.eof()){
          string word;
          words >> word;
          cout << word << " ";

        }
        words.close();
    }else{
        cout << "File not found!" << endl;
    }

    return 0;
}


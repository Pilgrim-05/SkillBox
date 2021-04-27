#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    string word;
    cout << "Enter your search word: ";
    cin >> word;
    std::ifstream words;
    words.open("../src/words.txt");

    if(words.is_open()){
        int counter = 0;
        while(!words.eof()){
          string tmpWord;
          words >> tmpWord;
          if(word == tmpWord) ++counter;
        }
        words.close();
        cout << endl << "number of coincidences: " << counter << endl;
    }else{
        cout << "File not found!" << endl;
    }

    return 0;
}

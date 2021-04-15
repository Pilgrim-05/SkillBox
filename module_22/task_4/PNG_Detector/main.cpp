#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool isPng(const string &path);

int main()
{
    cout << "Enter the full file name: ";
    string fileName;
    cin >> fileName;
    cout << (isPng(fileName)? "This is a png file" : "It is not a png file") << endl;

    return 0;
}

bool isPng(const string &path){
    std::ifstream iFile(path.c_str(), std::ios::binary);

    string fileType = path.substr(path.length()-4);
    if(fileType != ".png" && fileType != ".PNG") return false;
    char headNum;
    string headChar;
    if(iFile.is_open()){
        iFile >> headNum;
        for(int i = 0; i < 3; ++i){
            char tmp;
            iFile >> tmp;
            headChar +=tmp;
        }
        iFile.close();
    }else{
        cout << "File not found." << endl;
    }

    return (headNum == -119 && headChar == "PNG");
}

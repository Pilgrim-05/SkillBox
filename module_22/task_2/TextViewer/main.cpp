#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{    
    string fileName;
    cout << "Enter file name: ";
    cin >> fileName;
    std::ifstream ifile;

    ifile.open(fileName, std::ios::binary);
    if (ifile.is_open()){

       while(ifile){
         char buf[26];
         ifile.read(buf, sizeof(buf)-1);
         buf[ifile.gcount()] = '\0';
         cout << buf;
       }

       ifile.close();
    }else {
        std::cerr << "File not found!";
    }

    return 0;
}

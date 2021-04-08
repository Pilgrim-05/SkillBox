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

    ifile.open(fileName.c_str(), std::ios::binary);
    if (ifile.is_open()){

       while(ifile){
         char buf[25];
         ifile.read(buf, 25);
         buf[ifile.gcount()] = '\0';
         cout << buf;
       }

       ifile.close();
    }else {
        std::cerr << "File not found!";
    }

    return 0;
}

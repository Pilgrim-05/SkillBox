#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    std::srand(std::time(nullptr));
    std::ofstream fout("../src/pic.txt");

    if(fout.is_open()){
        int width;
        int height;
        cout << "width: ";
        cin >> width;
        cout << "height: ";
        cin >> height;

        for(int i = 0; i < height; ++i){
            for(int j = 0; j < width; ++j){

                int pix = std::rand() % 2;
                fout << pix;
            }
            fout << endl;
        }

        fout.close();
    }else {
        cout << "This file cannot be opened." << endl;
    }

    return 0;
}


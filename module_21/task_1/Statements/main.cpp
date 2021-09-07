#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct collective
{
    string name = "";
    string fname = "";
    string date = "";
    int many = 0;
};

void adding(string fileName);
void reading(string fileName, vector<collective>& vec);

const string fileName = "../src/statement.txt";

int main()
{
    std::vector <collective> person;
    string command = "";
    cout << "Enter the command add/read: ";
    cin >> command;
    if(command == "add")
    {
        adding(fileName);

    }else if(command == "read")
    {
        reading(fileName, person);
        cout << endl;
        for(collective p: person){
            cout << p.name << " " << p.fname << " " << p.date << " " << p.many << endl;
        }

    }else{
      cout << "Undefined command." << endl;
    }

    return 0;
}

void reading(string fileName, vector<collective>& vec)
{
    ifstream file(fileName);
    if(file.is_open())
    {
        while(!file.eof())
        {
            collective tmp;
            file >> tmp.name;
            file >> tmp.fname;
            file >> tmp.date;
            file >> tmp.many;

            if(tmp.name != "")
            {
                vec.push_back(tmp);
            }
        }
        file.close();
    }else{
        cout << "File not found!" << endl;
    }
}

void adding(string fileName)
{
    ofstream file(fileName, ios::app);
    if(file.is_open()){
      cout << "Enter data in the format: \"name surname DD.MM.YYYY salary\" " << endl;
      collective tmp;
      cin >> tmp.name >> tmp.fname >> tmp.date >> tmp.many;
      file << tmp.name << " " << tmp.fname << " " << tmp.date << " " << tmp.many << endl;
      file.close();
    }else{
        cout << "File not found!" << endl;
    }
}

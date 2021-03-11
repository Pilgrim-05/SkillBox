#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

using vector3d = vector<vector<vector<bool>>>;
void outCub(const vector3d v);
void fillCub(vector3d &v);
void cubeSection(const vector3d v, int sectionNumber);

int main()
{
     vector3d v(5, vector<vector<bool>>(5, vector<bool>(10, 0)));

     fillCub(v);
     cout << endl << "Enter section number: ";
     int sectionNumber;
     cin >> sectionNumber;
     while(sectionNumber > 9 || sectionNumber < 0){
         cout << "Incorrect section number!" << endl;
         cin >> sectionNumber;
     }
     cubeSection(v, sectionNumber);cout << endl << "************************" << endl;
     //outCub(v);

    return 0;
}

void cubeSection(const vector3d v, int sectionNumber ){
    cout << endl;
    for(int i = 0; i < v.size(); ++i)
    {
        for(int j = 0; j < v[i].size(); ++j)
        {
            cout << v[i][j][sectionNumber] << " ";
        }
        cout << endl;
    }
}

void outCub(const vector3d v)
{
    for(int i = 0; i < v.size(); ++i)
    {
        for(int j = 0; j < v[i].size(); ++j)
        {
            for(int k = 0; k < v[i][j].size(); ++k)
                cout << v[i][j][k] << " ";
            cout << endl;
        }
        cout << endl;
    }
}

void fillCub(vector3d &v)
{
    int z;
    for(int i = 0; i < v.size(); ++i){
        for(int j = 0; j < v[i].size(); ++j){
            cout << "column height " << i << ":" << j << " - ";
            cin >> z;

            while(z > 10 || z < 0){
                cout << "Incorrect input !" << endl;
                cin >> z;
            }
            for(int k = 0; k < z; ++k){
                v[i][j][k] = true;
            }
        }
    }
}



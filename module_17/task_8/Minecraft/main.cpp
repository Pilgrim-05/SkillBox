#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void outCub(const vector<vector <vector<int>>> v);
void fillCub(vector<vector <vector<int>>> &v);
void cubeSection(const vector<vector <vector<int>>> v, int sectionNumber);

int main()
{
     vector<vector <vector<int>>> v(5, vector<vector<int>>(5, vector <int> (10)) );

     fillCub(v);
     cout << endl << "Enter section number: ";
     int sectionNumber;
     cin >> sectionNumber;
     while(sectionNumber > 9 || sectionNumber < 0){
         cout << "Incorrect section number!" << endl;
         cin >> sectionNumber;
     }
     cubeSection(v, sectionNumber);
//     cout << endl << "************************" << endl;
//     outCub(v);

    return 0;
}

void cubeSection(const vector<vector <vector<int>>> v, int sectionNumber ){
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

void outCub(const vector<vector <vector<int>>> v)
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

void fillCub(vector<vector <vector<int>>> &v)
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

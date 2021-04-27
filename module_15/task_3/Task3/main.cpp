#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void sort(vector<int> &vec);

int main()
{
    vector<int> vec;
    int result = 0;
    cin >> result;

    while(result != -2)
    {

        if(result == -1 && vec.size() > 4){
            cout << vec[4] << endl;
        }else{
            vec.push_back(result);
            sort(vec);
        }
        cin >> result;
    }

    return 0;
}

void sort(vector<int> &vec)
{

    for(int i = vec.size()-1; i >=0 ; --i)
    {
        int max = 0;
        for(int j = 0; j <= i; ++j)
        {
            if(vec[j] > vec[max]) max = j;
        }
        int tmp = vec[i];
        vec[i] = vec[max];
        vec[max] = tmp;
    }
}

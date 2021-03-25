#include <iostream>
#include <vector>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void sort(vector<int> &vec);

int main()
{
    vector<int> vec = {-100, -50, -5, 1, 10, 15};

    sort(vec);

    for(int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }

    return 0;
}

void sort(vector<int> &vec)
{
    for(int i = vec.size()-1; i >=0; --i)
    {
        int max = 0;
        for(int j = 0; j <= i; ++j)
        {
            if(abs(vec[j]) > abs(vec[max])) max = j;
        }
        int tmp = vec[i];
        vec[i] = vec[max];
        vec[max] = tmp;
    }
}



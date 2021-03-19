#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
    vector<int> vec = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int summ = vec[0];
    int index_s = 0;
    int index_e = 0;

    for(size_t i = 0; i < vec.size()-1; ++i){
        int tmp = vec[i];
        for(size_t j = i + 1; j < vec.size(); ++j){
            tmp += vec[j];
            if(summ < tmp){
                summ = vec[i] + vec[j];
                index_s = i;
                index_e = j;
            }
        }
    }
    cout << index_s << " " << index_e << endl;

    return 0;
}


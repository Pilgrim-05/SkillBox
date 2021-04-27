#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
    vector<int> vec = {2, 7, 11, 15};
    int result;
    cin >> result;

    for(size_t i = 0; i < vec.size()-1; ++i){
        for(size_t j = i + 1; j < vec.size(); ++j){
            if(vec[i] + vec[j] == result){
               cout << vec[i] << " " << vec[j] << endl;
               return 0;
            }
        }
    }
    return 0;
}


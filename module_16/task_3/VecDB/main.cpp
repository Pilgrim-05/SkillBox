#include <iostream>
#include <vector>

using namespace std;

vector<int> shiftVector(vector<int> vec, int item);
void vectorItemShow(vector<int> vec, int size);

int main()
{
    int size = 20;
    vector<int> vec(size);
    int number;
    cin >> number;
    int length = 0;

    while(number != -1){
        if(length < size){
            vec[length] = number;
            ++length;
        }else{
            vec = shiftVector(vec, number);
        }
        cin >> number;
    }
    vectorItemShow(vec, length);

    return 0;
}

vector<int> shiftVector(vector<int> vec, int item){
    vector<int> newVec(vec.size());
    for(int i = 1; i < vec.size(); ++i){
        newVec[i-1] = vec[i];
    }
    newVec[vec.size() - 1] = item;
    return newVec;
}

void vectorItemShow(vector<int> vec, int size){
    for(size_t i = 0; i < size; i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}


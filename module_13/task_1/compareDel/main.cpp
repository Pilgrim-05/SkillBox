#include <iostream>
#include <vector>

using namespace std;

vector<int> vectorFilling(int size);
vector<int> rmFromVec(vector<int> vec, int item);
void vectorItemShow(vector<int> vec);

int main()
{
    cout << "Enter size vector: ";
    int size;
    cin >> size;

    if(size > 0){
        cout << "Enter " << size << " vector elements: ";
        vector<int> vec = vectorFilling(size);
        cout << "Enter the item to be deleted: ";
        int item;
        cin >> item;
        vec = rmFromVec(vec, item);
        vectorItemShow(vec);
    }else{
        cout << "You entered an incorrect size!" << endl;
    }

    return 0;
}
void vectorItemShow(vector<int> vec){
    for(size_t i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}

vector<int> rmFromVec(vector<int> vec, int item){
    vector<int> newVec;
    for(size_t i = 0; i < vec.size(); i++){
        if(vec[i] != item) newVec.push_back(vec[i]);
    }
    return newVec;
}

vector<int> vectorFilling(int size){
    vector<int> vec;
    for(int i = 0; i < size; ++i){
        int element;
        cin >> element;
        vec.push_back(element);
    }
    return vec;
}

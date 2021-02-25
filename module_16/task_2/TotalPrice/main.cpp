#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<float> vecPrice = {2.5, 4.25, 3.0, 10.0};
    vector<int> vecPurchase = {1, 4, 0, 3};

    float totalSumm = 0;

    for(size_t i = 0; i < vecPurchase.size(); i++){
        if(vecPurchase[i] < vecPrice.size()){
            totalSumm += vecPrice[vecPurchase[i]];
        }else{
            cout << "The product is not in the Base!" << endl;
        }
    }

    cout << "Total Price: " << totalSumm << endl;
}


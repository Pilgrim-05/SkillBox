#include <iostream>

using namespace std;

int main()
{
    cout << "**** My Quarter ****" << endl << endl;

    int building[] = {2, 1, 3, 15, 50};
    float averageFloors = 0;
    for(int i = 0; i < sizeof(building)/sizeof(building[0]); i++){
        averageFloors += building[i];
    }
    averageFloors /= 5;

    cout << "average number of storeys: " << averageFloors << endl;
    return 0;
}



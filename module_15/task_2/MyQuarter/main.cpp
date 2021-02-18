#include <iostream>

using namespace std;

int main()
{
    cout << "**** MyQuarter ****" << endl << endl;

    int building[] = {2, 1, 3, 15, 50};
    int building_1[3];
    int building_2[2];
    int building_3[5];
    int building_4[15];
    int building_5[50];
    int averageFloors = 0;
    for(int i = 0; i < sizeof(building)/sizeof(building[0]); i++){
        averageFloors += building[i];
    }
    averageFloors /= 5;

//    int averageFloors = (sizeof(building_1)/sizeof(building_1[0]) +
//            sizeof(building_2)/sizeof(building_2[0]) +
//            sizeof(building_3)/sizeof(building_3[0]) +
//            sizeof(building_4)/sizeof(building_4[0]) +
//            sizeof(building_5)/sizeof(building_5[0]))/5;

    cout << "average number of storeys: " << averageFloors << endl;
    return 0;
}



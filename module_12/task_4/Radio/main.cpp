#include <iostream>

using namespace std;

int main()
{
    cout << "**** Radio receiver ****" << endl;
    float channels[]= {92.5, 90.8, 100.0, 100.5, 101.5, 95.5, 105.8, 102.0, 104.5, 95.0};
    int station;
    do{
        cin >> station;
        if(station > sizeof(channels)/sizeof(channels[0])){
            cout << "Error! such channel is not configured.\n";
        }else if(station != 0){
            cout << "listening to radio station " << channels[station-1] << endl;
        }

    }while(station != 0);

    return 0;
}


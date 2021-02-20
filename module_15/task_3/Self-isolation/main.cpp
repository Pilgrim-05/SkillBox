#include <iostream>

using namespace std;

int main()
{
    cout << "***** self-isolation *****" << endl << endl;

    cout << "Total number of residents of the house: ";
    int numberOfResidents;
    cin >> numberOfResidents;
    const int FLOORS = 5;
    int personOnTheFloor[FLOORS];
    int totalPeople = 0;
    for(int i = 0; i < FLOORS; i++){
        cout << "number of people on the " << i + 1 << " st floor: ";
        cin >> personOnTheFloor[i];
        totalPeople += personOnTheFloor[i];
    }
    if(numberOfResidents < totalPeople){
        cout << "\nAttention! strangers into the building!\n";
    }else{
        totalPeople *= 100;
        cout << "\nGeneral level of self-isolation in the house " << (float)totalPeople/numberOfResidents << "% \n";
    }

    return 0;
}


#include <iostream>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

enum tumblers{
    MAINSWITCH = 1,
    MAINSOCKETS = 2,
    HOUSEBULB = 4,
    STREETBULB = 8,
    HEATING = 16,
    WATERHEATING = 32,
    CONDITIONER = 64
};

void sensorsDate(std::stringstream& buff, const int& hour, char &flags);
void monitoring(const char& state, const int& hour);

int main()
{
        char flags = 0;
        for(int time = 0; time < 48; ++time){
            int hour = time % 24;
            if(hour < 10)cout << "HOUR: " << " " << hour << ":00" << endl;
            else cout << "HOUR: " << hour << ":00" << endl;
            cout << "Enter sensor states: ";
            string state;
            std::getline(cin, state);
            std::stringstream stringBuff;
            stringBuff.str(state);

            sensorsDate(stringBuff, hour, flags);
            monitoring(flags, hour);
        }

    return 0;
}

void sensorsDate(std::stringstream& buff, const int& hour, char &flags){
    double outTempSensor = 0;
    double inTempSensor = 0;
    string motionSensor;
    string homelight;

    buff >> outTempSensor;
    buff >> inTempSensor;
    buff >> motionSensor;
    buff >> homelight;

    flags |= MAINSWITCH;
    flags |= MAINSOCKETS;

    if(flags & MAINSWITCH){
        if(outTempSensor < 0) flags |= WATERHEATING;
        else if(outTempSensor > 5) flags &= ~WATERHEATING;

        if(motionSensor == "yes" && (hour > 16 || hour < 5)) flags |= STREETBULB;
        else flags &= ~STREETBULB;

        if(inTempSensor < 22) flags |= HEATING;
        else if(inTempSensor >= 25) flags &= ~HEATING;

        if((flags & MAINSOCKETS) && inTempSensor >= 30) flags |= CONDITIONER;
        else if((flags & MAINSOCKETS) || inTempSensor <= 25) flags &= ~CONDITIONER;

        if(homelight == "on") flags |= HOUSEBULB;
        else flags &= ~HOUSEBULB;
    }
}

void monitoring(const char& flags, const int& hour){
    int light = 5000;
    if(hour > 16 && hour <= 20) light = 5000 - ((hour - 16) * 575);
    else if(hour == 0) light = 5000;

    cout << endl << "*************************" << endl;

    if(flags & MAINSWITCH) cout << "POWER: on" << endl;
    else cout << "POWER: off" << endl;

    if(flags & MAINSOCKETS) cout << "SOCKETS: on" << endl;
    else cout << "SOCKETS: off" << endl;

    if(flags & HOUSEBULB) cout << "LIGHT IN HOUSE: " << light << endl;
    else cout << "LIGHT IN HOUSE: off" << endl;

    if(flags & STREETBULB) cout << "STREET LIGHTING: on" << endl;
    else cout << "STREET LIGHTING: off" << endl;

    if(flags & HEATING) cout << "HEATING: on" << endl;
    else cout << "HEATING: off" << endl;

    if(flags & WATERHEATING) cout << "WATER HEATING: on" << endl;
    else cout << "WATER HEATING: off" << endl;

    if(flags & CONDITIONER) cout << "CONDITIONER: on" << endl;
    else cout << "CONDITIONER: off" << endl;

    cout << endl << "*************************" << endl;
}

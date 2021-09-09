#include <iostream>
#include <vector>

using namespace std;
struct room
{
    string name;
    int area;
};

struct floor
{
    int num;
    int height;
    int numRooms;
    vector<room> rooms;
};

struct build
{
    string name;
    int area;
    int numFloor;
    vector<floor> floors;
    bool stove = false;
};

struct plot
{
    int id;
    int numBuilds = 1;
    vector<build> builds;
};

int main()
{
    cout << "number of land plots: ";
    int numPlot;
    cin >> numPlot;
    vector<plot> town(numPlot);
    for(int i = 0; i < numPlot; ++i)
    {
        town[i].id = i + 1;
        cout << "number of buildings on site No. " << i + 1 <<": ";
        cin >> town[i].numBuilds;
        while(town[i].numBuilds < 1)
        {
            cout << "the number of buildings on the site is not less than 1" << endl;
            cout << "number of buildings on site No. " << i + 1 <<": ";
            cin >> town[i].numBuilds;
        }
        town[i].builds.resize(town[i].numBuilds);
        for(int j = 0; j < town[i].numBuilds; ++j)
        {
            cout << "which building? house, bathhouse, garage, etc.: ";
            cin >> town[i].builds[j].name;
            cout << "building area: ";
            cin >> town[i].builds[j].area;
            if(town[i].builds[j].name == "house")
            {
                cout << "number of floors: ";
                cin >> town[i].builds[j].numFloor;
                while(town[i].builds[j].numFloor < 1 || town[i].builds[j].numFloor > 3)
                {
                    cout << "number of floors in the range 1 - 3!" << endl;
                    cout << "number of floors: ";
                    cin >> town[i].builds[j].numFloor;
                }
                town[i].builds[j].floors.resize(town[i].builds[j].numFloor);
                for(int k = 0; k < town[i].builds[j].numFloor; ++k)
                {
                    town[i].builds[j].floors[k].num = k + 1;
                    cout << "ceiling height of this floor: ";
                    cin >> town[i].builds[j].floors[k].height;
                    cout << "number of rooms: ";
                    cin >> town[i].builds[j].floors[k].numRooms;
                    while(town[i].builds[j].floors[k].numRooms < 2 || town[i].builds[j].floors[k].numRooms > 4)
                    {
                        cout << "number of rooms in the range 2 - 4" << endl;
                        cout << "number of rooms: ";
                        cin >> town[i].builds[j].floors[k].numRooms;
                    }
                    town[i].builds[j].floors[k].rooms.resize(town[i].builds[j].floors[k].numRooms);
                    for(int l = 0; l < town[i].builds[j].floors[k].numRooms; ++l)
                    {
                        cout << "which room? (bedroom, kitchen, etc.): ";
                        cin >> town[i].builds[j].floors[k].rooms[l].name;
                        cout << "room area: ";
                        cin >> town[i].builds[j].floors[k].rooms[l].area;
                    }
                }

                cout << "is there a stove? (yes/no): ";
                string answer;
                cin >> answer;
                town[i].builds[j].stove = (answer == "yes")? true: false;

            }else if(town[i].builds[j].name == "bathhouse")
            {
                cout << "is there a stove? (yes/no): ";
                string answer;
                cin >> answer;
                town[i].builds[j].stove = (answer == "yes")? true: false;
            }
        }
    }

    return 0;
}

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <limits>

struct Train
{
    std::string name = "none";
    int speed;
};

std::mutex station;

void moveTrain(const Train &t)
{
    std::this_thread::sleep_for(std::chrono::seconds(t.speed));


    if(station.try_lock())
        station.unlock();
    else
        std::cout << "\ntrain " << t.name << " is awaiting the release of the station." << std::endl;

    station.lock();
    std::cout << "Arrival of train " << t.name << std::endl;
    std::string command;
    do{
        std::cout << "Free the train station (depart): ";
        std::getline(std::cin, command);
    }while(command != "depart");

     std::cout << "Departure of train  " << t.name << std::endl;
     station.unlock();
}


using namespace std;

int main() {
    vector<Train> trains(3);

    for(int i = 0; i < trains.size(); ++i)
    {
        cout << "Enter the name of the train: ";
        string name;
        getline(cin, name);
        cout << "Enter travel time: ";
        int time;
        cin >> time;
        cin.ignore(numeric_limits<int>::max(), '\n');

        trains[i].name = name;
        trains[i].speed = time;
    }

    vector<thread> trainThreads(3);

    for(int i = 0; i < trainThreads.size(); ++i)
        trainThreads[i] = thread(moveTrain, trains[i]);

    for(int i = 0; i < trainThreads.size(); ++i)
        trainThreads[i].join();

    return 0;
}

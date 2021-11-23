#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <limits>

struct rating
{
    std::string name;
    int finish;
};

std::vector<rating> ratings;
std::mutex mtx;

void swimmer(std::string name, int speed);

using namespace std;

int main()
{
    vector<string> swName(6);
    vector<int> swSpeed(6);

    for(int i = 0; i < swName.size(); ++i)
    {
        cout << "Swimmer's name: ";
        getline(cin, swName[i]);
        cout << "Swimmer speed: ";
        cin >> swSpeed[i];
        cin.ignore(numeric_limits<int>::max(), '\n');
    }

    std::vector<std::thread> threads(6);
    for(int i = 0; i < threads.size(); ++i)
    {
        threads[i] = thread(swimmer, swName[i], swSpeed[i]);
    }


    for(int i = 0; i < threads.size(); ++i)
    {
        threads[i].join();
    }

    cout << "\n***********Swim rating***********\n";
    mtx.lock();
    for(int i = 0; i < ratings.size(); ++i)
    {
        cout << ratings[i].name << " \t:\t " << ratings[i].finish << endl;
    }
    mtx.unlock();

    return 0;
}

void swimmer(std::string name, int speed)
{
    int distance = 0;
    while(distance < 100)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        distance +=speed;
        if(distance > 100) distance = 100;
        std::cout << "Distance " << name << ": " <<  distance << std::endl;
    }

    rating tmp;
    tmp.name = name;
    if(distance % speed == 0) tmp.finish = distance/speed;
    else tmp.finish = distance / speed + 1;

    mtx.lock();
    ratings.push_back(tmp);
    mtx.unlock();

}

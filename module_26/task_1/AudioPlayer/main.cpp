#include <iostream>
#include <vector>
#include "track.h"
#include "player.h"
#include <iomanip>

using namespace std;

void playTrack(vector<Track> &playList)
{
    for(auto i : playList)
    {
        tm creation = i.getCreation();
        std::cout << "Name: " << i.getName() << " Created: " << put_time(&creation, "%Y/%m/%d") << " Duration: " << i.getDuration() << std::endl;

    }
}


int main()
{
    cout << "Enter the number of tracks in the playlist: ";
    int number;
    cin >> number;
    cin.ignore(32767, '\n');
    vector<Track> playList;
    for(int i = 0; i < number; ++i)
    {
        Track *tr = new Track();
        tr->addTrack();
        playList.push_back(*tr);
        delete tr;
    }

    cout << "****************Play List****************\n";
    playTrack(playList);
    cout << "*****************************************\n";

    Player *player = new Player();
    player->setPlayList(playList);

    string command;
    cout << "Enter your command(play/pause/next/stop/exit): ";
    getline(cin, command);

    while(command != "exit")
    {
        if(command == "play")
        {
            player->play();

        }else if(command == "pause")
        {
            player->pause();
        }else if(command == "next")
        {
            player->next();
        }else if(command == "stop")
        {
            player->stop();
        }

        cout << "Enter your command(play/pause/next/stop/exit): ";
        getline(cin, command);
    }

    delete player;

    return 0;
}

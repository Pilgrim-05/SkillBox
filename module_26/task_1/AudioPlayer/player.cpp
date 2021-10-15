#include "player.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

Player::Player()
{
    activeTrack = -1;
    playbackStatus = false;
}

void Player::setPlayList(const std::vector<Track> &pl)
{
    trackList.resize(pl.size());
    for(int i = 0; i < pl.size(); ++i)
    {
        trackList[i] = pl[i];
    }
}

void Player::play()
{
    if(activeTrack == -1)
    {
        std::cout << "Enter track name: ";
        std::string name;
        getline(std::cin, name);
        int i;
        for(i = 0; i < trackList.size(); ++i)
        {
            if(name == trackList[i].getName())
            {
                playTrack(i);
            }
        }
    }else if(activeTrack != -1 && !playbackStatus)
    {
        playTrack(activeTrack);
    }
}

void Player::pause()
{
    if(activeTrack != -1 && playbackStatus)
    {
        std::cout << trackList[activeTrack].getName() << " Paused" << std::endl;
    }
    playbackStatus = false;
}

void Player::next()
{
    int range = trackList.size();
    srand(time(nullptr));
    int index = rand() % range;
    playTrack(index);
}

void Player::playTrack(const int index)
{
    tm creation = trackList[index].getCreation();
    std::cout << "Name: " << trackList[index].getName() << " Created: " << std::put_time(&creation, "%Y/%m/%d") << " Duration: " << trackList[index].getDuration() << " sec." << std::endl;
    activeTrack = index;
    playbackStatus = true;
}

void Player::stop()
{
    if(activeTrack != -1)
    {
        std::cout << "Play is stopped!" << std::endl;
    }
    activeTrack = -1;
    playbackStatus = false;
}

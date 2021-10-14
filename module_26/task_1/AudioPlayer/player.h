#pragma once
#include <vector>
#include "track.h"


class Player
{
private:
    std::vector<Track> trackList;
    int activeTrack;
    bool playbackStatus;

    void playTrack(const int);

public:
    Player();
    void setPlayList(const std::vector<Track> &pl);
    void play();
    void pause();
    void next();
    void stop();
};

#pragma once
#include <string>
#include <ctime>


class Track
{
private:
    std::string name;
    std::tm creation;
    unsigned long duration;
public:
    Track();
    void addTrack();
    std::string getName();
    std::tm getCreation();
    unsigned long getDuration();
};

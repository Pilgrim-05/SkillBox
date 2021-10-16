#include "track.h"
#include <iostream>
#include <iomanip>

Track::Track(){}

void Track::addTrack()
{
    time_t time = std::time(nullptr);
    creation = *localtime(&time);
    std::cout << "Track name: ";
    std::cin >> name;
    std::cout << "Track creation date:(YYYY/mm/dd) ";
    std::cin >> std::get_time(&creation, "%Y/%m/%d");
    std::cout << "Track duration in seconds: ";
    std::cin >> duration;
    std::cin.ignore(32767,'\n');
}

std::string Track::getName()
{
    return name;
}

tm Track::getCreation()
{
    return creation;
}

unsigned long Track::getDuration()
{
    return duration;
}

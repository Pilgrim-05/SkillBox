#pragma once
#include <exception>

class Fortune : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Good fishing!";
    }
};

class Failure : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Bad fishing! Better luck next time.";
    }
};


enum class Content{FISH = 1, BOOT = -1, FREE = 0};

class Field
{
private:
    Content content;
public:
    Field();
    Field& operator=(const Content &inContent);
    void fishing();
    Content get();
};

#pragma once
#include <string>

class Profile
{
    std::string name;
    unsigned int points;

    Profile(std::string name, unsigned int points) : name(name), points(points) {}
    friend class ProfileFactory;

public:
    std::string getName() const
    {
        return name;
    }

    unsigned int getPoints() const
    {
        return points;
    }

    void incrementPoints()
    {
        points++;
    }
};
#pragma once
#include <string>

class Profile
{
    std::string name;
    signed int points;

    Profile(std::string name, unsigned int points) : name(name), points(points) {}
    friend class ProfileFactory;

public:
    std::string getName() const
    {
        return name;
    }

    signed int getPoints() const
    {
        return points;
    }

    void incrementPoints()
    {
        points++;
    }

    void decrementPoints()
    {
        points--;
    }
};
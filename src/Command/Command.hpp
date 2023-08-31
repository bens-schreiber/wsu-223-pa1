#pragma once
#include <iostream>
#include <string>

class Command
{
    std::string name;
    std::string description;

    Command(std::string name, std::string description) : name(name), description(description) {}
    friend class CommandFactory;

public:
    inline std::string getName() const
    {
        return name;
    }

    inline std::string getDescription() const
    {
        return description;
    }

    inline bool operator==(const Command &other) const
    {
        return name == other.name;
    }

    inline friend std::ostream &operator<<(std::ostream &os, const Command &command)
    {
        os << command.name;
        return os;
    }
};
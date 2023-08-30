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
    std::string getName() const
    {
        return name;
    }

    std::string getDescription() const
    {
        return description;
    }

    bool operator==(const Command &other) const
    {
        return name == other.name;
    }

    friend std::ostream &operator<<(std::ostream &os, const Command &command)
    {
        os << command.name;
        return os;
    }
};
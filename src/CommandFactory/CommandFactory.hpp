#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class Command
{
    friend CommandFactory;
    std::string name;
    std::string description;

    Command(std::string name, std::string description) : name(name), description(description) {}

public:
    std::string getName() const
    {
        return name;
    }

    std::string getDescription() const
    {
        return description;
    }
};

class CommandFactory
{

    static Command fromCSV(std::istringstream &ss)
    {
        std::string name, description;
        std::getline(ss, name, ',');
        std::getline(ss, description, ',');
        return Command(name, description);
    }

public:
    static std::vector<Command> fromCSVFile(std::ifstream file)
    {
        std::vector<Command> commands;
        std::string line;
        while (std::getline(file, line))
        {
            std::istringstream ss(line);

            commands.push_back(CommandFactory::fromCSV(ss));
        }
        return commands;
    }
};
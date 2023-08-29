#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Command.hpp"

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
    static std::vector<Command> fromCSVFile(std::ifstream &file)
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
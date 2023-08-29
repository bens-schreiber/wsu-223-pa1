#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Command.hpp"
#include "../LinkedList/LinkedList.hpp"
#include "../utils/FinallyBlock.hpp"

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

    static LinkedList<Command> &fromCSVFile(std::ifstream &file)
    {
        LinkedList<Command> *commands = new LinkedList<Command>();
        std::string line;
        while (std::getline(file, line))
        {
            std::istringstream ss(line);
            commands->add(CommandFactory::fromCSV(ss));
        }
        return *commands;
    }

    static LinkedList<Command> &fromCSVFile(std::string path) {
        std::ifstream file(path);
        FinallyBlock finally([&]() {
            file.close();
        });
        return CommandFactory::fromCSVFile(file);
    }
};
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "../consts.hpp"
#include "../Command/CommandFactory.hpp"
#include "../Profile/ProfileFactory.hpp"
#include "../LinkedList/LinkedList.hpp"

int testFetchCommands()
{
    std::ifstream file(COMMANDS_PATH);

    if (!file.is_open())
    {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    LinkedList<Command> commands = CommandFactory::fromCSVFile(file);
    commands.print();

    file.close();
    return 0;
}

int testFetchProfiles()
{
    std::ifstream file(PROFILES_PATH);

    if (!file.is_open())
    {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    LinkedList<Profile> profiles = ProfileFactory::fromCSVFile(file);
    profiles.print();

    file.close();
    return 0;
}
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
#include "../SaveContent/SaveContent.hpp"

int testFetchCommands()
{
    std::ifstream file(COMMANDS_PATH);

    if (!file.is_open())
    {
        if (TEST_OUTPUTS) std::cout << "Error opening file" << std::endl;
        return 1;
    }

    LinkedList<Command> commands = CommandFactory::fromCSVFile(file);
    if (TEST_OUTPUTS) commands.print();

    file.close();
    return 0;
}

int testFetchProfiles()
{
    std::ifstream file(PROFILES_PATH);

    if (!file.is_open())
    {
        if (TEST_OUTPUTS) std::cout << "Error opening file" << std::endl;
        return 1;
    }
    Profile *profiles = ProfileFactory::fromCSVFile(file);

    // enumerate profiles
    for (int i = 0; profiles[i].getName() != ""; i++)
    {
        if (TEST_OUTPUTS) std::cout << profiles[i].getName() << ", " << profiles[i].getPoints() << std::endl;
    }

    // dispose
    delete[] profiles;
    file.close();

    return 0;
}

int testSaveProfiles() {
    std::ifstream file(PROFILES_PATH);

    if (!file.is_open())
    {
        if (TEST_OUTPUTS) std::cout << "Error opening file" << std::endl;
        return 1;
    }

    // Load the profiles
    Profile *profiles = ProfileFactory::fromCSVFile(file);

    // Save the points of the first profile
    const auto points = profiles[0].getPoints();

    // Increment the points of the first profile
    profiles[0].incrementPoints();

    file.close();

    // Attempt a save
    SaveContent::saveProfiles(profiles);
    delete[] profiles;


    // Open a new file stream to the profile path
    std::ifstream file2(PROFILES_PATH);
    if (!file2.is_open())
    {
        if (TEST_OUTPUTS) std::cout << "Error opening file" << std::endl;
        return 1;
    }

    // Load the profiles again
    profiles = ProfileFactory::fromCSVFile(file2);

    assert(profiles[0].getPoints() == points + 1);

    // Dispose
    delete[] profiles;
    file2.close();

    return 0;

}
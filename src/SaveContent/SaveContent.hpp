#pragma once
#include <iostream>
#include <fstream>
#include "../consts.hpp"
#include "../LinkedList/LinkedList.hpp"
#include "../Profile/Profile.hpp"

namespace SaveContent
{
    // Save the profiles to the profile file
    void saveProfiles(Profile *profiles);

    // Save all commands to the command file
    void saveCommands(LinkedList<Command> &commands);
}
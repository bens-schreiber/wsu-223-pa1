#pragma once
#include <iostream>
#include <fstream>
#include "../consts.hpp"
#include "../Profile/Profile.hpp"

namespace SaveContent
{
    // Save the profiles to the profile file
    void saveProfiles(Profile *profiles)
    {

        std::ofstream file(PROFILES_PATH);
        if (!file.is_open())
        {
            std::cout << "Error opening file" << std::endl;
            return;
        }

        // enumerate profiles while not nullptr
        while (profiles->getName() != "")
        {
            file << profiles->getName() << "," << profiles->getPoints() << std::endl;
            profiles++;
        }
        file.close();
    }
}
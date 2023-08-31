#pragma once
#include <iostream>
#include <fstream>
#include "../consts.hpp"
#include "../Profile/Profile.hpp"

namespace SaveContent
{
    // Save the profiles to the profile file
    void saveProfiles(Profile *profiles);
}
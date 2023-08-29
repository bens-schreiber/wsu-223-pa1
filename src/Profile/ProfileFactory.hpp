#include "Profile.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class ProfileFactory
{
    static Profile fromCSV(std::istringstream &ss)
    {
        std::string name;
        unsigned int points;
        std::getline(ss, name, ',');
        ss >> points;
        return Profile(name, points);
    }

public:
    static std::vector<Profile> fromCSVFile(std::ifstream &file)
    {
        std::vector<Profile> profiles;
        std::string line;
        while (std::getline(file, line))
        {
            std::istringstream ss(line);

            profiles.push_back(ProfileFactory::fromCSV(ss));
        }
        return profiles;
    }
};
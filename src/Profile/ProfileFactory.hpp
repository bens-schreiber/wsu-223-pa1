#pragma once
#include "Profile.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../LinkedList/LinkedList.hpp"

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

    static LinkedList<Profile> &fromCSVFile(std::ifstream &file)
    {
        LinkedList<Profile> *profiles = new LinkedList<Profile>();
        std::string line;
        while (std::getline(file, line))
        {
            std::istringstream ss(line);
            profiles->add(ProfileFactory::fromCSV(ss));
        }
        return *profiles;
    }
};
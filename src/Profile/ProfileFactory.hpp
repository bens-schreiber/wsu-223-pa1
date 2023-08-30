#pragma once
#include "Profile.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../utils/FinallyBlock.hpp"

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

    static Profile* &fromCSVFile(std::ifstream &file)
    {
        Profile **profiles = new Profile*[100];
        std::string line;
        int i = 0;
        while (std::getline(file, line))
        {
            std::istringstream ss(line);
            if (ss.str() == "") break;
            profiles[i] = new Profile(ProfileFactory::fromCSV(ss));
            i++;
        }
        profiles[i] = new Profile("", 0);
        
        return *profiles;
    }

    static Profile* fromCSVFile(std::string path)
    {
        std::ifstream file(path);
        FinallyBlock finally([&]() {
            file.close();
        });
        return ProfileFactory::fromCSVFile(file);
    }
};
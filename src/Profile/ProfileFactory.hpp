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

    static Profile* &fromCSVFile(std::ifstream &file);

    inline static Profile* fromCSVFile(std::string path)
    {
        std::ifstream file(path);
        FinallyBlock finally([&]() {
            file.close();
        });
        return ProfileFactory::fromCSVFile(file);
    }
};
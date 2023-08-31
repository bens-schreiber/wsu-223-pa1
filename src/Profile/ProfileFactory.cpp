#include "ProfileFactory.hpp"

Profile *&ProfileFactory::fromCSVFile(std::ifstream &file)
{
    Profile **profiles = new Profile *[100];
    std::string line;
    int i = 0;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        if (ss.str() == "")
            break;
        profiles[i] = new Profile(ProfileFactory::fromCSV(ss));
        i++;
    }
    profiles[i] = new Profile("", 0);

    return *profiles;
}
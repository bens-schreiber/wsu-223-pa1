#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "../consts.hpp"
#include "../Command/CommandFactory.hpp"
#include "../Profile/ProfileFactory.hpp"

int testFetchCommands() {
    std::ifstream file(COMMANDS_PATH);
    std::vector<Command> commands = CommandFactory::fromCSVFile(file);

    if (!file.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    auto iter = 1;
    for (const auto &command : commands) {
        std::cout << iter++ << " " << command.getName() << " - " << command.getDescription() << std::endl;
    }
    file.close();
    return 0;
}

int testFetchProfiles() {
    std::ifstream file(PROFILES_PATH);
    std::vector<Profile> profiles = ProfileFactory::fromCSVFile(file);

    if (!file.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    auto iter = 1;
    for (const auto &profile : profiles) {
        std::cout << iter++ << " " << profile.getName() << " - " << profile.getPoints() << std::endl;
    }
    file.close();
    return 0;
}
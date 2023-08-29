#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "CommandFactory/CommandFactory.hpp"

#define PATH "/Users/benjaminschreiber/dev/wsu-223-pa1/assets/commands.csv"

int main() {
    std::ifstream file(PATH);
    std::vector<Command> commands = CommandFactory::fromCSVFile(file);

    if (!file.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    for (const auto &command : commands) {
        std::cout << command.getName() << " - " << command.getDescription() << std::endl;
    }
    file.close();
    return 0;
}
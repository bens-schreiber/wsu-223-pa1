#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "CommandFactory/CommandFactory.hpp"

int main() {
    std::ifstream file("assets/commands.csv");
    std::vector<Command> commands = CommandFactory::fromCSVFile(file);
    for (const auto &command : commands) {
        std::cout << command.getName() << " - " << command.getDescription() << std::endl;
    }
    file.close();
    return 0;
}
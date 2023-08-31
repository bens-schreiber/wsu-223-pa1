#include "CommandFactory.hpp"

LinkedList<Command> &CommandFactory::fromCSVFile(std::ifstream &file)
{
    LinkedList<Command> *commands = new LinkedList<Command>();
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        commands->add(CommandFactory::fromCSV(ss));
    }
    return *commands;
}
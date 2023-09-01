#include "SaveContent.hpp"
void SaveContent::saveProfiles(Profile *profiles)
{

    std::ofstream file(PROFILES_PATH);
    if (!file.is_open())
    {
        std::cout << "Error opening file" << std::endl;
        return;
    }

    // enumerate profiles while not nullptr
    while (profiles->getName() != "")
    {
        file << profiles->getName() << "," << profiles->getPoints() << std::endl;
        profiles++;
    }
    file.close();
}

void SaveContent::saveCommands(LinkedList<Command> &commands)
{
    std::ofstream file(COMMANDS_PATH);
    if (!file.is_open())
    {
        std::cout << "Error opening file" << std::endl;
        return;
    }

    // enumerate commands while not nullptr
    auto iterator = commands.getHead();
    while (iterator != nullptr)
    {
        file << iterator->getData().getName() << "," << iterator->getData().getDescription() << std::endl;
        iterator = iterator->getNext();
    }

    file.close();
}
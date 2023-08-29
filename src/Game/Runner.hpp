#include "../Command/CommandFactory.hpp"
#include "../Profile/ProfileFactory.hpp"
#include "../consts.hpp"

namespace GameRunner
{

    // A game where the player has to match the description of a linux command with the name of a command.
    // The player is shown a list of all commands, and then is asked to match the name of the command with the description.
    // For every correct answer, the player gets a point.
    void run()
    {
        LinkedList<Command> &commands = CommandFactory::fromCSVFile(COMMANDS_PATH);
        LinkedList<Profile> &profiles = ProfileFactory::fromCSVFile(PROFILES_PATH);

        std::cout << "\nPress Enter to see all commands";
        std::cin.get();
        commands.print();

        std::cout << "\nPress Enter to exit";
        std::cin.get(); // Wait for Enter key
    }
}
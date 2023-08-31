#include <iostream>
#include <cstdlib>
#include "../consts.hpp"
#include "../test/test.hpp"
#include "../Game/Game.hpp"
#include "../SaveContent/SaveContent.hpp"
#include "../utils/utils.hpp"

namespace Menu
{
    typedef void (*Option)();

    class Options
    {
        static void printRules()
        {
            clearOutput();
            std::cout << "Select the matching description to a command. If your answer is correct, you will gain a point. " << std::endl
                      << "If your answer is incorrect, you will lose a point" << std::endl << std::endl
                      << "Press enter to Continue";
            std::cin.ignore();
            std::cin.get();
        }
        static void playGame()
        {
            std::srand(static_cast<unsigned int>(std::time(nullptr)));

            LinkedList<Command> &commands = CommandFactory::fromCSVFile(COMMANDS_PATH);
            Profile *profiles = ProfileFactory::fromCSVFile(PROFILES_PATH);
            Game::start(profiles, commands);
            SaveContent::saveProfiles(profiles);
        }

        static void loadGame()
        {
            return;
        }

        static void addCommand()
        {
            return;
        }

        static void removeCommand()
        {
            return;
        }

        static void exit()
        {
            std::cout << "Goodbye!" << std::endl;
            std::exit(0);
        }

    public:
        static Option *enumerate()
        {
            static Option options[] = {
                printRules,
                playGame,
                loadGame,
                addCommand,
                removeCommand,
                exit,
                nullptr};
            return options;
        }
    };

    void display()
    {
        clearOutput();
        // Display options: 1) Print rules, 2) play game, 3) load previous game, 4) add command, 5) remove command, 6) exit
        std::cout << "1. Print rules" << std::endl
                  << "2. Play game" << std::endl
                  << "3. Load Previous Game" << std::endl
                  << "4. Add Command" << std::endl
                  << "5. Remove Command" << std::endl
                  << "6. Exit" << std::endl
                  << "Enter a number: ";
    }

    void run()
    {
        while (1)
        {
            display();

            int input;
            while (!(std::cin >> input) || input < 1 || input > 6)
            {
                std::cout << "Invalid input, please enter a number between 1 and 6" << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }

            // run the selected option
            Option *options = Options::enumerate();
            options[input - 1]();
        }
    }
}
#pragma once
#include <iostream>
#include <cstdlib>
#include "../consts.hpp"
#include "../test/test.hpp"
#include "../Game/Game.hpp"
#include "../utils/utils.hpp"

namespace Menu
{
    typedef void (*Option)();

    class Options
    {
        static void printRules();

        static void playGame();

        static void loadGame();

        static void addCommand();

        static void removeCommand();

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
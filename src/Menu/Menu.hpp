#pragma once
#include <iostream>
#include <cstdlib>
#include "../SaveContent/SaveContent.hpp"
#include "../consts.hpp"
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

        inline static void exit()
        {
            std::cout << "Goodbye!" << std::endl;
            std::exit(0);
        }

    public:
        inline static Option *enumerate()
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

    inline void display()
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

    // Run the menu loop
    void run();
}
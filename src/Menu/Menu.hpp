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

        static void exit();

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

    void display();

    // Run the menu loop
    void run();
}
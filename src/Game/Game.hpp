#pragma once
#include <vector>
#include <algorithm>
#include <random>
#include "../utils/utils.hpp"
#include "../Command/CommandFactory.hpp"
#include "../Profile/ProfileFactory.hpp"
#include "../consts.hpp"

class Game
{
    Profile *profile;
    LinkedList<Command> &commands;
    Node<Command> *iterator;
    std::vector<Command> display = {};

    Game(Profile *profile, LinkedList<Command> &commands, Node<Command> *iterator) : profile(profile), commands(commands), iterator(iterator) {}
    ~Game() {}

    void doRound();
    void shuffleDisplay();
    void enumerateDisplay() const;
    void inputLoop(Command &);

    void run()
    {
        while (iterator != nullptr)
        {
            clearOutput();
            std::cout << "Points: " << profile->getPoints() << std::endl;

            doRound();

            // Await input before next question
            std::cout << "\nPress Enter for the next quesiton";
            std::cin.get();

            // Continue the game
            display.clear();
            iterator = iterator->getNext();
        }
    }

public:
    // Begins a game with some profile and command list
    static void start(Profile *profiles, LinkedList<Command> &commands)
    {
        Game game(profiles, commands, commands.getHead());

        std::cout << "\nPress Enter to begin";
        std::cin.get();
        game.run();
    }
};
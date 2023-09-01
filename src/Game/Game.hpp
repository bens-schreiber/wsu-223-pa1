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
    unsigned char questions;

    Game(Profile *profile, LinkedList<Command> &commands, Node<Command> *iterator, unsigned char questions) : profile(profile), commands(commands), iterator(iterator), questions(questions) {}
    ~Game() {}

    void doRound();
    void shuffleDisplay();
    void enumerateDisplay() const;
    void inputLoop(Command &);

    void run();

public:
    // Begins a game with some profile and command list
    inline static void start(Profile *profiles, LinkedList<Command> &commands, unsigned char questions)
    {
        Game game(profiles, commands, commands.getHead(), questions);

        std::cout << "\nPress Enter to begin";
        std::cin.get();
        game.run();
    }
};
#include <vector>
#include <algorithm>
#include <random>
#include "../Command/CommandFactory.hpp"
#include "../Profile/ProfileFactory.hpp"
#include "../consts.hpp"

// (via ChatGPT)
void clearScreen()
{
#ifdef _WIN32
    system("cls"); // For Windows
#else
    std::cout << "\x1B[2J\x1B[H"; // For Unix-like systems (including macOS and Linux)
#endif
}

namespace GameRunner
{

    // A game where the player has to match the description of a linux command with the name of a command.
    // The player is shown a list of all commands, and then is asked to match the name of the command with the description.
    // For every correct answer, the player gets a point.
    void run(LinkedList<Command> &commands, Profile *profiles)
    {

        Profile &profile = profiles[0];

        // Used to shuffle the commands and enumerate
        std::vector<Command> display;

        std::cout << "\nPress Enter to begin";
        std::cin.get();

        // enumerate through the entire linked list
        auto iterator = commands.getHead();
        while (iterator != nullptr)
        {
            clearScreen();
            std::cout << "Points: " << profile.getPoints() << std::endl;

            // Command to match
            Command answer = iterator->getData();
            std::cout << answer.getName() << std::endl
                      << std::endl;

            // Add the command to match and two randoms to the game commands
            // LinkedList::random takes in an exclusion list, so we won't get the same command twice.
            display.push_back(iterator->getData());
            display.push_back(commands.random(display));
            display.push_back(commands.random(display));

            // Create a random number generator
            std::random_device rd;
            std::mt19937 gen(rd());

            // Shuffle the vector using std::shuffle
            std::shuffle(display.begin(), display.end(), gen);

            // Display all commands
            for (auto i = 0; i < display.size(); ++i)
            {
                std::cout << "  " << i + 1 << ". " << display[i].getDescription() << std::endl
                          << std::endl;
            }

            // Input loop
            while (1)
            {
                try
                {
                    // Accept input
                    std::cout << "Enter the number of the correct answer: ";
                    std::string input;
                    std::getline(std::cin, input);

                    if (display[std::stoi(input) - 1] == answer)
                    {
                        std::cout << "Correct!" << std::endl;
                        profile.incrementPoints();
                    }
                    else
                    {
                        std::cout << "Incorrect!" << std::endl;
                    }
                    break;
                }
                catch (...)
                {
                    std::cout << "Invalid input" << std::endl;
                }
            }

            // Await input before next question
            std::cout << "\nPress Enter for the next quesiton";
            std::cin.get();

            // Continue the game
            display.clear();
            iterator = iterator->getNext();
        }

        std::cout << "\nPress Enter to exit";
        std::cin.get();
    }
}

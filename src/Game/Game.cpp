#include "Game.hpp"

void Game::clearScreen() const
{
#ifdef _WIN32
    system("cls"); // For Windows
#else
    std::cout << "\x1B[2J\x1B[H"; // For Unix-like systems (including macOS and Linux)
#endif
}

void Game::doRound()
{

    // Command to match
    Command answer = iterator->getData();

    std::cout << answer.getName() << std::endl
              << std::endl;

    // Add the command to match and two randoms to the game commands
    // LinkedList::random takes in an exclusion list, so we won't get the same command twice.
    display.push_back(iterator->getData());
    display.push_back(commands.random(display));
    display.push_back(commands.random(display));

    // Shuffle the output of commands so the order isn't consistent
    shuffleDisplay();

    // Output
    enumerateDisplay();

    inputLoop(answer);
}

void Game::shuffleDisplay()
{
    // Create a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Shuffle the vector using std::shuffle
    std::shuffle(display.begin(), display.end(), gen);
}

void Game::enumerateDisplay() const
{
    // Display all commands
    for (auto i = 0; i < display.size(); ++i)
    {
        std::cout << "  " << i + 1 << ". " << display[i].getDescription() << std::endl
                  << std::endl;
    }
}

void Game::inputLoop(Command &answer)
{
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
                profile->incrementPoints();
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
}
#include "Menu.hpp"

/*

    By the project requirements, profiles and commands should only be saved on exit,
    thus requiring us to cache them here in static variables

*/

static Profile *_profiles = nullptr;

static LinkedList<Command> *_commands = nullptr;

Profile *profiles()
{
    _profiles = _profiles == nullptr ? ProfileFactory::fromCSVFile(PROFILES_PATH) : _profiles;
    return _profiles;
}

LinkedList<Command> &commands()
{
    _commands = _commands == nullptr ? &CommandFactory::fromCSVFile(COMMANDS_PATH) : _commands;
    return *_commands;
}

void Menu::display()
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

void Menu::run()
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

// Output the game rules
void Menu::Options::printRules()
{
    clearOutput();
    std::cout << "Select the matching description to a command. If your answer is correct, you will gain a point. " << std::endl
              << "If your answer is incorrect, you will lose a point" << std::endl
              << std::endl
              << "Press enter to Continue";
    std::cin.ignore();
    std::cin.get();
}

// Begin a game with the default profile and command list
void Menu::Options::playGame()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // ask how many questions
    auto questions = 0;
    std::cout << "How many questions would you like to answer? (5-30): ";
    while (!(std::cin >> questions) || questions < 5 || questions > 30)
    {
        std::cout << "Invalid input, please enter a number between 5 and 30" << std::endl;
        std::cin.clear();
        std::cin.ignore();
    }

    Game::start(profiles(), commands(), questions);
}

// Attempt to load and play a player profile
void Menu::Options::loadGame()
{

    // Since we clear output everytime, store the notFound variable in a static variable
    // so when the function is reursively called we may know a scenario
    static bool notFound = false;

    clearOutput();
    if (notFound)
        std::cout << "Profile not found" << std::endl;

    // Exit or continue
    int input;
    std::cout << "1. Enter a profile name" << std::endl
              << "2. Exit" << std::endl
              << "Enter a number: ";

    // Get a valid input
    while (!(std::cin >> input) || input < 1 || input > 2)
    {
        std::cout << "Invalid input, please enter a number between 1 and 2" << std::endl;
        std::cin.clear();
        std::cin.ignore();
    }

    // Exit
    if (input == 2)
        return;

    // Get a valid profile input
    std::string name;
    std::cout << "Enter a profile name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    for (int i = 0; profiles()[i].getName() != ""; i++)
    {
        if (std::tolower(profiles()[i].getName()[0]) == std::tolower(name[0]))
        {

            playGame();
            notFound = false;
            return;
        }
    }

    // Profile wasn't found, recursively call again
    notFound = true;
    loadGame();
    return;
}

// Add a command to _commands
void Menu::Options::addCommand()
{

    std::string name;
    std::string description;

    std::cout << "Enter a command name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Enter a command description: ";
    std::getline(std::cin, description);

    Command newCommand(name, description);
    commands().add(newCommand);
}

// Remove a command from _commands
void Menu::Options::removeCommand()
{
    std::string name;

    std::cout << "Enter a command name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    Command newCommand(name, "");
    commands().remove(newCommand);
}

void Menu::Options::exit()
{
    std::cout << "Goodbye!" << std::endl;
    SaveContent::saveProfiles(profiles());
    SaveContent::saveCommands(commands());
    std::exit(0);
}
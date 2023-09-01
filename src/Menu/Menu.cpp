#include "Menu.hpp"

static Profile *_profiles = nullptr;

Profile *profiles()
{
    return _profiles == nullptr ? ProfileFactory::fromCSVFile(PROFILES_PATH) : _profiles;
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

    LinkedList<Command> &commands = CommandFactory::fromCSVFile(COMMANDS_PATH);
    _profiles = profiles();
    Game::start(_profiles, commands);
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

    _profiles = profiles();
    for (int i = 0; _profiles[i].getName() != ""; i++)
    {
        if (std::tolower(_profiles[i].getName()[0]) == std::tolower(name[0]))
        {

            // Profile found, run the game with this profile
            Game::start(&_profiles[i], CommandFactory::fromCSVFile(COMMANDS_PATH));
            notFound = false;
            return;
        }
    }

    // Profile wasn't found, recursively call again
    notFound = true;
    loadGame();
    return;
}

// Add a command to the command list
void Menu::Options::addCommand()
{
    // clearOutput();
    // std::cout << "Enter a command name: ";
    // std::string name;
    // std::getline(std::cin, name);

    // std::cout << "Enter a command description: ";
    // std::string description;
    // std::getline(std::cin, description);

    // Command command(name, description);
    // SaveContent::saveCommand(command);
}

// Remove a command from the command list
void Menu::Options::removeCommand()
{
    // clearOutput();
    // std::cout << "Enter a command name: ";
    // std::string name;
    // std::getline(std::cin, name);

    // Command command(name, "");
    // SaveContent::removeCommand(command);
}

void Menu::Options::exit()
{
    std::cout << "Goodbye!" << std::endl;
    SaveContent::saveProfiles(profiles());
    std::exit(0);
}
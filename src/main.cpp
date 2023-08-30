#include <cstdlib>
#include "consts.hpp"
#include "test/test.hpp"
#include "Game/Runner.hpp"
#include "SaveContent/SaveContent.hpp"

/*

    ADVANTAGE / DISADVANTAGE LINKED LIST:
    When using a linked list, you get constant insertion time, works fine for the act of
    loading the CSV file, and inserting new items. However, when you want to access/remove an item of a specific
    index, or id, you have to iterate through the list, which is linear time.

*/

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    if (RUN_TESTS)
    {
        return testFetchCommands() || testFetchProfiles() || testSaveProfiles();
    }

    LinkedList<Command> &commands = CommandFactory::fromCSVFile(COMMANDS_PATH);
    Profile *profiles = ProfileFactory::fromCSVFile(PROFILES_PATH);
    GameRunner::run(commands, profiles);
    SaveContent::saveProfiles(profiles);

    return 0;
}
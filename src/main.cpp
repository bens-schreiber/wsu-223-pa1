#include <cstdlib>
#include "consts.hpp"
#include "Menu/Menu.hpp"
#include "test/test.hpp"

/*

    ADVANTAGE / DISADVANTAGE LINKED LIST:
    When using a linked list, you get constant insertion time, works fine for the act of
    loading the CSV file, and inserting new items. However, when you want to access/remove an item of a specific
    index, or id, you have to iterate through the list, which is linear time.

*/

int main()
{
    if (RUN_TESTS) return Test::fetchCommands() || Test::fetchProfiles() || Test::saveProfiles();
    Menu::run();
    return 0;
}
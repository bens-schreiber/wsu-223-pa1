#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "../consts.hpp"
#include "../Command/CommandFactory.hpp"
#include "../Profile/ProfileFactory.hpp"
#include "../LinkedList/LinkedList.hpp"
#include "../SaveContent/SaveContent.hpp"

namespace Test
{
    inline int fetchCommands()
    {
        std::ifstream file(COMMANDS_PATH);

        if (!file.is_open())
        {
            if (TEST_OUTPUTS)
                std::cout << "Error opening file" << std::endl;
            return 1;
        }

        LinkedList<Command> commands = CommandFactory::fromCSVFile(file);
        if (TEST_OUTPUTS)
            commands.print();

        file.close();
        return 0;
    }

    int fetchProfiles();

    int saveProfiles();
}

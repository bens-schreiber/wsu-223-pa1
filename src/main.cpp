#include "consts.hpp"
#include "test/test.hpp"

int main() {
    if (RUN_TESTS) {
        return testFetchCommands() || testFetchProfiles();
    }
    return 0;
}
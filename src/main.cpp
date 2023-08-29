#include "consts.hpp"
#include "test/test.hpp"

int main() {
    if (RUN_TESTS) {
        return testFetchCommands();
    }
    return 0;
}
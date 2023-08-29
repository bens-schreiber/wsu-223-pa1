#pragma once
#include <iostream>
#include <stdexcept>

// dumb language
// this makes use of the destructor which is called whenever the object goes out of scope to call some cleanup function
class FinallyBlock {
public:
    FinallyBlock(std::function<void()> finallyAction) : action(finallyAction) {}
    ~FinallyBlock() {
        action();
    }

private:
    std::function<void()> action;
};
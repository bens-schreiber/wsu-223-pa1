#pragma once
#include <iostream>

inline void clearOutput()
{
#ifdef _WIN32
    system("cls"); // For Windows
#else
    std::cout << "\x1B[2J\x1B[H"; // For Unix-like systems (including macOS and Linux)
#endif
}
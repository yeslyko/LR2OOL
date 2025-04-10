#include "timeplayed.h"

Timer::Timer()
{
    init_time = std::chrono::steady_clock::now();
}

int Timer::GetTime()
{
    std::chrono::time_point<std::chrono::steady_clock> now = std::chrono::steady_clock::now();
    return std::chrono::duration<double>(now - init_time).count();
}
#include "Timer.h"

long long zong::Timer::elapsed() const
{
    return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - _now).count();
}
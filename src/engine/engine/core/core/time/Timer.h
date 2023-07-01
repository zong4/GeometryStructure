#pragma once

#include <chrono>

namespace zong
{

/**
 * \brief a timer
 */
class Timer
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> _now;

public:
    Timer() { reset(); }

    inline void reset() { _now = std::chrono::high_resolution_clock::now(); }

    long long elapsed() const;
    long long elapsedMillis() const { return elapsed() * 1000; }
};

} // namespace zong

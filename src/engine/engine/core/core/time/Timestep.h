#pragma once

namespace zong
{

/**
 * \brief time step
 */
class Timestep
{
private:
    float _time;

public:
    explicit Timestep(float time = 0.0f) : _time(time) {}

    inline float time() const { return _time; }
    inline float seconds() const { return time(); }
    inline float milliseconds() const { return time() * 1000.0f; }

    // operator float() const { return _time; }
};

} // namespace zong
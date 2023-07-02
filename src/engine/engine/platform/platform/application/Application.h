#pragma once

#include <platform/pch.h>

#include "../window/Window.h"

namespace zong
{
namespace platform
{

/**
 * \brief the client will public Application to create a app
 */
class Application
{
private:
    bool                    _running;
    std::unique_ptr<Window> _window;

public:
    Application() : _running(true), _window(Window::create()) {}
    virtual ~Application() {}

    inline bool                           running() const { return _running; }
    inline std::unique_ptr<Window> const& window() const { return _window; }

    void Init();
    void Run();
};

//  be defined in client
std::unique_ptr<Application> CreateApplication();

} // namespace platform
} // namespace zong
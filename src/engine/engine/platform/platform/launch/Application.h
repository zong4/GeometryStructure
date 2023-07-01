#pragma once

#include <platform/pch.h>

#include "window/Window.h"

namespace zong
{

/**
 * \brief the client will public Application to create a app
 */
class Application
{
private:
    static std::unique_ptr<Window> _window;

public:
    Application() {}
    virtual ~Application() {}

    void Init();
    void Run();
};

//  be defined in client
std::unique_ptr<Application> CreateApplication();

} // namespace zong
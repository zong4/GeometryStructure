#pragma once

#include <memory>

namespace zong
{

class Application
{
public:
    Application();
    virtual ~Application();

    void Init();
    void Run();
};

//  be defined in client
std::unique_ptr<Application> CreateApplication();

} // namespace zong
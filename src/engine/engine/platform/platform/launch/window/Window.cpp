#include "Window.h"

#ifdef WINDOWS
    #include "./windows/WindowsWindow.h"
#elif LINUX
    #include "./linux/LinuxWindow.h"
#endif

std::unique_ptr<zong::Window> zong::Window::create(WindowProps const& props)
{
#ifdef WINDOWS
    return std::make_unique<WindowsWindow>(props);
#elif LINUX
    return std::make_unique<LinuxWindow>(props);
#else
    HZ_CORE_ASSERT(false, "Unknown platform!");
    return nullptr;
#endif
}
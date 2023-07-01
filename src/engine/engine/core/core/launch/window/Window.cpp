#include "Window.h"

#ifdef WINDOWS
// #include "Platform/Windows/WindowsWindow.h"
#endif

namespace zong
{
std::unique_ptr<Window> Window::Create(WindowProps const& props)
{
#ifdef WINDOWS
    // return CreateScope<WindowsWindow>(props);
#else
    ZONG_CORE_ERROR(false, "Unknown platform!");
    return nullptr;
#endif
    return nullptr;
}

} // namespace zong
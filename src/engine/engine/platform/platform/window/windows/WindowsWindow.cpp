#include "WindowsWindow.h"

void zong::platform::WindowsWindow::setVSync(bool enabled)
{
    if (enabled)
        glfwSwapInterval(1);
    else
        glfwSwapInterval(0);

    _data._isVSync = enabled;
}

void zong::platform::WindowsWindow::init(WindowProps const& props)
{
    _data._title  = props._title;
    _data._width  = props._width;
    _data._height = props._height;

    ZONG_CORE_INFO("Creating window {0} ({1}, {2})", props._title, props._width, props._height);

    if (!init())
    {
        // TODO: glfwTerminate on system shutdown
        int success = glfwInit();
        ZONG_CORE_ASSERT(success, "Could not intialize GLFW!");

        setInit(true);
    }

    _window = glfwCreateWindow(static_cast<int>(props._width), static_cast<int>(props._height), _data._title.c_str(), nullptr, nullptr);

    glfwMakeContextCurrent(_window);
    glfwSetWindowUserPointer(_window, &_data);

    setVSync(true);
}

void zong::platform::WindowsWindow::update()
{
    glfwPollEvents();
    glfwSwapBuffers(_window);
}

void zong::platform::WindowsWindow::shutdown()
{
    glfwDestroyWindow(_window);
    if (_window)
        int i = 1;
}

#include "Application.h"

#include <GLFW/glfw3.h>
#include <gl/GL.h>

void zong::platform::Application::Init()
{
    ZONG_CORE_TRACE("init engine");

#ifdef WINDOWS
    ZONG_CORE_TRACE("windows platform");
#elif LINUX
    ZONG_CORE_TRACE("linux platform");
#endif
}

void zong::platform::Application::Run()
{
    while (running())
    {
        glClearColor(1, 0, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        window()->update();
    }
}
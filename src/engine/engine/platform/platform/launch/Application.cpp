#include "Application.h"

void zong::Application::Init()
{
    ZONG_CORE_TRACE("init engine");

#ifdef WINDOWS
    ZONG_CORE_TRACE("windows platform");
#elif LINUX
    ZONG_CORE_TRACE("linux platform");
#endif
}

void zong::Application::Run()
{
    while (true)
    {
        WindowResizeEvent e(1280, 720);
        if (e.isInCategory(EventCategory::EventCategoryApplication))
        {
            ZONG_CORE_TRACE(e.toString());
        }
        if (e.isInCategory(EventCategory::EventCategoryInput))
        {
            ZONG_CORE_INFO(e.toString());
        }
    }
}
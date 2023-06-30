#include "Application.h"

#include "../log/Log.h"

zong::Application::Application()
{
}

zong::Application::~Application()
{
}

void zong::Application::Init()
{
#ifdef WINDOWS
    ZONG_CORE_TRACE("windows platform");
#elif LINUX
    ZONG_CORE_TRACE("linux platform");
#endif

    ZONG_CORE_TRACE("init engine");
}

void zong::Application::Run()
{
    while (true)
    {
    }
}
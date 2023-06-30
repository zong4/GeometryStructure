#pragma once

#include "Application.h"

#ifdef WINDOWS
    #include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
    auto const app = zong::CreateApplication();

    app->Init();
    app->Run();

    return 0;
}

#elif define LINUX

int main(int argc, char** argv)
{
    auto const app = zong::CreateApplication();

    app->Init();
    app->Run();

    return 0;
}

#endif

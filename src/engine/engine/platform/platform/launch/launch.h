#pragma once

#include "../application/Application.h"

#ifndef TEST
    #ifdef WINDOWS
        #include <windows.h>

// int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
int main(int argc, char** argv)
{
    // call the console window
    AllocConsole();

    auto const app = zong::platform::CreateApplication();

    app->Init();
    app->Run();

    return 0;
}

    #elif LINUX

int main(int argc, char** argv)
{
    auto const app = zong::platform::CreateApplication();

    app->Init();
    app->Run();

    return 0;
}

    #endif

#endif
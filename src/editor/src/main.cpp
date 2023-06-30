/*! \mainpage Main page
# Quick Start
一些使用说明。
*/

#include <engine/engine.h>

#include <iostream>
#include <vector>

class Editor : public zong::Application
{
public:
    Editor() {}
    ~Editor() {}
};

std::unique_ptr<zong::Application> zong::CreateApplication()
{
    return std::make_unique<Editor>();
}

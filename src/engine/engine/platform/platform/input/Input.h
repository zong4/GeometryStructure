#pragma once

#include <glm/glm.hpp>

#include "platform/pch.h"

namespace zong
{
namespace platform
{

class Input
{
public:
    static bool isKeyPressed(core::KeyCode key);

    static bool      isMouseButtonPressed(core::MouseCode button);
    static glm::vec2 getMousePosition();
    static float     getMouseX();
    static float     getMouseY();
};

} // namespace platform
} // namespace zong
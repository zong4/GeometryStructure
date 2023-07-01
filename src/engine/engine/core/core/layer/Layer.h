#pragma once

#include "../event/Event.h"
#include "../time/Timestep.h"
#include "core/pch.h"

namespace zong
{

class Layer
{
private:
    std::string _name;

public:
    Layer(std::string const& name = "Layer") : _name(name) {}
    virtual ~Layer() = default;

    inline std::string name() const { return _name; }

    virtual void onAttach() = 0;
    virtual void onDetach() = 0;

    virtual void onUpdate(Timestep const& ts) = 0;
    virtual void onImGuiRender()              = 0;
    virtual void onEvent(Event& event)        = 0;
};

} // namespace zong
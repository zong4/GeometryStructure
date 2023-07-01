#pragma once

#include "platform/pch.h"

namespace zong
{

struct WindowProps
{
    std::string _title;
    uint32_t    _width;
    uint32_t    _height;

    WindowProps(std::string const& title = "Engine", uint32_t width = 1600, uint32_t height = 900)
        : _title(title), _width(width), _height(height)
    {
    }
};

/**
 * \brief interface representing a desktop system based window
 */
class Window
{
private:
public:
    using EventCallbackFn = std::function<void(Event&)>;

    Window()          = default;
    virtual ~Window() = default;

    virtual uint32_t width() const  = 0;
    virtual uint32_t height() const = 0;

    // TODO: open
    // virtual void* nativeWindow() const = 0;

    // window attributes
    virtual void setEventCallback(const EventCallbackFn& callback) = 0;
    virtual void setVSync(bool enabled)                            = 0;

    virtual bool isVSync() const = 0;

    virtual void update() = 0;

    static std::unique_ptr<Window> create(WindowProps const& props = WindowProps());
};

} // namespace zong

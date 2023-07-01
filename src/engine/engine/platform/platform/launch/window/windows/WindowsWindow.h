#pragma once

#include <GLFW/glfw3.h>

#include "../Window.h"

namespace zong
{

class WindowsWindow : public Window
{
private:
    /**
     * \brief be managed by GLFW
     */
    GLFWwindow* _window;
    bool        _init;

    struct WindowData
    {
        std::string  _title;
        unsigned int _width, _height;
        bool         _isVSync;

        EventCallbackFn EventCallback;

        WindowData() = default;
    };

    WindowData _data;

public:
    WindowsWindow(WindowProps const& props) : Window(), _init(false) { init(props); }
    virtual ~WindowsWindow() { shutdown(); }

    inline bool         init() const { return _init; }
    inline unsigned int width() const override { return _data._width; }
    inline unsigned int height() const override { return _data._height; }
    inline bool         isVSync() const override { return _data._isVSync; }

    inline void setInit(bool value) { _init = value; }
    inline void setEventCallback(EventCallbackFn const& callback) override { _data.EventCallback = callback; }
    void        setVSync(bool enabled) override;

    void init(const WindowProps& props);
    void update() override;
    void shutdown();
};

} // namespace zong
#pragma once

#include "core.h"
#include "event/event.h"

namespace hezel
{

struct WindowProps
{
    std::string title;
    unsigned int width;
    unsigned int height;
    
    WindowProps(
        const std::string &title = "Hezel Engine",
        unsigned int width = 1280,
        unsigned int height = 720
    ) : title(title), width(width), height(height) {}
};

class Window
{
public:
    using EventCallbackFn = std::function<void(Event&)>;
    
    virtual ~Window() {}
    virtual void OnUpdate() = 0;
    virtual unsigned int get_width() const = 0;
    virtual unsigned int get_height() const = 0;
    
    virtual void SetEventCallback(const EventCallbackFn &callback) = 0;
    virtual void SetVSync(bool enabled) = 0;
    virtual bool IsVSync() const = 0;
    virtual void* GetNativeWindow() const = 0;
    
    static Window* Create(const WindowProps& props = WindowProps());
};

}
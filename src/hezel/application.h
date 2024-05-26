#pragma once

#include "event/event.h"
#include "window.h"

namespace hezel
{
class Application
{
public:
    Application();
    virtual ~Application();
    
    void Run();
private:
    std::unique_ptr<Window> m_window;
    bool m_running = true;
};
    
Application* createApplication();
} // namespace name

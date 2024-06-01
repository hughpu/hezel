#pragma once

#include "event/event.h"
#include "event/application_event.h"
#include "window.h"

namespace hezel
{
class Application
{
public:
    Application();
    virtual ~Application();
    
    void Run();
    void OnEvent(Event &event);

private:
    bool OnWindowClose(WindowCloseEvent &event);
    std::unique_ptr<Window> m_window;
    bool m_running = true;
};
    
Application* createApplication();
} // namespace name

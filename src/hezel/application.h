#pragma once

#include "event/event.h"
#include "event/application_event.h"
#include "window.h"
#include "layer_stack.h"

namespace hezel
{
class Application
{
public:
    Application();
    virtual ~Application();
    
    void Run();
    void OnEvent(Event &event);
    void PushLayer(Layer *layer);
    void PushOverLayer(Layer *overlay);

private:
    bool OnWindowClose(WindowCloseEvent &event);
    std::unique_ptr<Window> m_window;
    bool m_running = true;
    LayerStack m_layer_stack;
};
    
Application* createApplication();
} // namespace name

#include "application.h"
#include "event/application_event.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace hezel
{


Application* Application::s_instance = nullptr;

Application::Application()
{
    HZ_CORE_ASSERT(!s_instance, "Application already exists");
    s_instance = this;
    m_window = std::unique_ptr<Window>(Window::Create());
    m_window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
}

Application::~Application()
{
}

void Application::OnEvent(Event &event)
{
    EventDispatcher dispatcher(event);
    dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
    
    for (auto it = m_layer_stack.end(); it != m_layer_stack.begin();)
    {
        (*--it)->OnEvent(event);
        if (event.Handled)
            break;
    }
}

void Application::PushLayer(Layer *layer)
{
    m_layer_stack.PushLayer(layer);
    layer->OnAttach();
}

void Application::PushOverLayer(Layer *overlay)
{
    m_layer_stack.PushOverLayer(overlay);
    overlay->OnAttach();
}

void Application::Run()
{
    while (m_running)
    {
        glClearColor(1, 0, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        
        for (Layer* layer: m_layer_stack)
            layer->OnUpdate();

        m_window->OnUpdate();
    }
}

bool Application::OnWindowClose(WindowCloseEvent &event)
{
    m_running = false;
    return true;
}
}
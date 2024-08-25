#include "application.h"
#include "event/application_event.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace hezel
{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

Application* Application::s_instance = nullptr;

Application::Application()
{
    HZ_CORE_ASSERT(!s_instance, "Application already exists");
    m_window = std::unique_ptr<Window>(Window::Create());
    m_window->SetEventCallback(BIND_EVENT_FN(OnEvent));
}

Application::~Application()
{
}

void Application::OnEvent(Event &event)
{
    EventDispatcher dispatcher(event);
    dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
    
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
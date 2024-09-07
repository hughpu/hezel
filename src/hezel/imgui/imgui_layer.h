#pragma once

#include <hezel/layer.h>
#include <hezel/event/application_event.h>
#include <hezel/event/key_event.h>
#include <hezel/event/mouse_event.h>

namespace hezel
{

class ImGuiLayer : public Layer
{
public:
    ImGuiLayer();
    ~ImGuiLayer();    
    
    void OnAttach();
    void OnDetach();
    void OnUpdate();
    void OnEvent(Event& event);
private:
    bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
    bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
    bool OnMouseMovedEvent(MouseMovedEvent& e);
    bool OnMouseScrolledEvent(MouseScrolledEvent& e);

    bool OnKeyPressedEvent(KeyPressedEvent& e);
    bool OnKeyReleasedEvent(KeyReleasedEvent& e);
    bool OnKeyTypedEvent(KeyTypedEvent& e);
    
    bool OnWindowResizeEvent(WindowResizeEvent& e);

private:
    float m_time = 0.0f;
};

}


#include "hezel.h"

#include "stdio.h"
#include "cassert"


class ExampleLayer : public hezel::Layer
{
public:
    ExampleLayer() : Layer("Example")
    {
    }
    
    void OnUpdate() override
    {
        HZ_CLIENT_INFO("ExampleLayer::Update");
    }
    
    void OnEvent(hezel::Event &event) override
    {
        if (event.GetEventType() == hezel::EventType::kMouseMoved) {
            HZ_CLIENT_TRACE("Mouse Pos: ({0}, {1})", hezel::HezelInput::GetMouseX(), hezel::HezelInput::GetMouseY());
        }
    }
};

class Sandbox : public hezel::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
        PushOverLayer(new hezel::ImGuiLayer());
    }
    
    ~Sandbox()
    {
    }
};

hezel::Application* hezel::createApplication()
{
    return new Sandbox();
}
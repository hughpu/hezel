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
        HZ_CLIENT_TRACE("{0}", event);
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
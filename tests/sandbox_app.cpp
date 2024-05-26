#include "application.h"
#include "hezel/event/application_event.h"
#include "entrypoint.h"
#include "stdio.h"
#include "cassert"

class Sandbox : public hezel::Application
{
public:
    Sandbox()
    {
        
    }
    
    ~Sandbox()
    {
        
    }
};

hezel::Application* hezel::createApplication()
{
    return new Sandbox();
}
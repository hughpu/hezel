#include "application.h"
#include "entrypoint.h"

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
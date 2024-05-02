#include "application.h"
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
    
    void run() override {
        assert(true && "test for user defined app can run");
    }
};

hezel::Application* hezel::createApplication()
{
    return new Sandbox();
}
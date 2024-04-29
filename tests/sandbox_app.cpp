#include "application.h"

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

int main()
{
    Sandbox* sandbox = new Sandbox();
    sandbox->run();
    delete sandbox;
}
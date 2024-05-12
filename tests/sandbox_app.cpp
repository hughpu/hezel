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
    
    void run() override {
        hezel::WindowResizeEvent e(1280, 720);
        
        if (e.IsInCategory(hezel::EventCategory::kEventCategoryApplication))
        {
            HZ_CORE_TRACE(e);
        }
        
        if (e.IsInCategory(hezel::EventCategory::kEventCategoryInput))
        {
            HZ_CORE_TRACE(e);
        }

        assert(true && "test for user defined app can run");
    }
};

hezel::Application* hezel::createApplication()
{
    return new Sandbox();
}
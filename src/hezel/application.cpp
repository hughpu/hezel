#include "application.h"
#include "event/application_event.h"
#include "log.h"

namespace hezel
{
    Application::Application()
    {
    }
    
    Application::~Application()
    {
    }
    
    void Application::run()
    {
        // WindowResizeEvent e(1280, 720);
        
        // if (e.IsInCategory(EventCategory::kEventCategoryApplication))
        // {
        //     HZ_CORE_TRACE(e);
        // }
        
        // if (e.IsInCategory(EventCategory::kEventCategoryInput))
        // {
        //     HZ_CORE_TRACE(e);
        // }

        while (true);
    }
}
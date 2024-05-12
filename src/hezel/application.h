#pragma once

#include "event/event.h"

namespace hezel
{
    class Application {
    public:
        Application();
        virtual ~Application();
        
        virtual void run();
    };
    
    Application* createApplication();
} // namespace name

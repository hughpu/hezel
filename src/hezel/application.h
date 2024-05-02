#pragma once

#include <spdlog/spdlog.h>

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

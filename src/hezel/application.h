#pragma once

namespace hezel
{
    class Application {
    public:
        Application();
        virtual ~Application();
        
        void run();
    };
    
    Application* createApplication();
} // namespace name

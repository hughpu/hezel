#pragma once
#include "application.h"
#include "log.h"

extern hezel::Application* hezel::createApplication();

int main(int args, char** argsv)
{
    hezel::Log::Init();
    HZ_CORE_WARN("Initialized Log!");
    HZ_CLIENT_INFO("Hello! var={0}", 5);

    hezel::Application* app = hezel::createApplication();
    app->run();
    delete app;
}

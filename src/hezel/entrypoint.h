#pragma once
#include "application.h"

extern hezel::Application* hezel::createApplication();

int main(int args, char** argsv)
{
    hezel::Application* app = hezel::createApplication();
    app->run();
    delete app;
}

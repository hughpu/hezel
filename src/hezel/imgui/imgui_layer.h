#pragma once

#include "hezel/layer.h"

namespace hezel
{

class ImGuiLayer : public Layer
{
public:
    ImGuiLayer();
    ~ImGuiLayer();    
    
    void OnAttach();
    void OnDetach();
    void OnUpdate();
    void OnEvent(Event& event);

private:
    float m_time = 0.0f;
};

}


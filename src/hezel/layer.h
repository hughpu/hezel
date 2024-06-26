#pragma once

#include "hezel/core.h"
#include "event/event.h"

namespace hezel
{
    
class Layer
{
public:
    Layer(const std::string &name = "Layer");
    virtual ~Layer();
    
    virtual void OnAttach() {} ;
    virtual void OnDetach() {} ;
    virtual void OnUpdate() {} ;
    virtual void OnEvent(Event &event) {} ;
    
    inline const std::string& GetName() const { return m_debug_name; }

protected:
    std::string m_debug_name;
};
}
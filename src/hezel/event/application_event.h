#pragma once

#include "event.h"
#include <spdlog/fmt/ostr.h>

namespace hezel
{
class WindowResizeEvent : public Event
{
public:
    WindowResizeEvent(unsigned int width, unsigned int height)
        : m_width(width), m_height(height) {}
    
    unsigned int get_width() const { return m_width; };
    unsigned int get_height() const { return m_height; };
    
    const std::string ToString() const override
    {
        std::stringstream ss;
        ss << "WindoeResizeEvent: " << m_width << ", " << m_height;
        return ss.str();
    }
    
    EVENT_CLASS_TYPE(kWindowResize)
    EVENT_CLASS_CATEGORY(kEventCategoryApplication)

private:
    unsigned int m_width, m_height;
};


class WindowCloseEvent : public Event
{
public:
    WindowCloseEvent() {}
    
    EVENT_CLASS_TYPE(kWindowClose)
    EVENT_CLASS_CATEGORY(kEventCategoryApplication)
};

class AppTickEvent : public Event
{
public:
    AppTickEvent() {}
    
    EVENT_CLASS_TYPE(kAppTick)
    EVENT_CLASS_CATEGORY(kEventCategoryApplication)
};

class AppUpdateEvent : public Event
{
public:
    AppUpdateEvent() {}
    
    EVENT_CLASS_TYPE(kAppUpdate)
    EVENT_CLASS_CATEGORY(kEventCategoryApplication)
};

class AppRenderEvent : public Event
{
public:
    AppRenderEvent() {}
    
    EVENT_CLASS_TYPE(kAppRender)
    EVENT_CLASS_CATEGORY(kEventCategoryApplication)
};
}

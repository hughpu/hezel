#pragma once

#include "event.h"

#include <sstream>

namespace hezel
{
class MouseMovedEvent : public Event
{
public:
    MouseMovedEvent(float x, float y)
        : m_mouse_x(x), m_mouse_y(y) {}
    
    float get_x() const { return m_mouse_x; }
    float get_y() const { return m_mouse_y; }
    
    const std::string ToString() const override
    {
        std::stringstream ss;
        ss << "MouseMovedEvent: " << m_mouse_x << ", " << m_mouse_y;
        return ss.str();
    }
    
    EVENT_CLASS_TYPE(kMouseMoved)
    EVENT_CLASS_CATEGORY(kEventCategoryMouse | kEventCategoryInput)

private:
    float m_mouse_x, m_mouse_y;
};

class MouseScrolledEvent : public Event
{
public:
    MouseScrolledEvent(float x_offset, float y_offset)
        : m_xoffset(x_offset), m_yoffset(y_offset) {}
    
    float get_xoffset() const { return m_xoffset; }
    float get_yoffset() const { return m_yoffset; }
    
    const std::string ToString() const override
    {
        std::stringstream ss;
        ss << "MouseScrolledEvent: " << m_xoffset << ", " << m_yoffset;
        return ss.str();
    }
    
    EVENT_CLASS_TYPE(kMouseScrolled)
    EVENT_CLASS_CATEGORY(kEventCategoryMouse | kEventCategoryInput)

private:
    float m_xoffset, m_yoffset;
};

class MouseButtonEvent : public Event
{
public:
    int get_mouse_button() const { return m_button; }
    
    EVENT_CLASS_CATEGORY(kEventCategoryMouse | kEventCategoryInput)


protected:
    MouseButtonEvent(int button)
        : m_button(button) {}

    int m_button;
};

class MouseButtonPressedEvent : public MouseButtonEvent
{
public:
    MouseButtonPressedEvent(int button)
        : MouseButtonEvent(button) {}

    const std::string ToString() const override
    {
        std::stringstream ss;
        ss << "MouseButtonPressedEvent: " << m_button;
        return ss.str();
    }

    EVENT_CLASS_TYPE(kMouseButtonPressed);
};

class MouseButtonReleasedEvent : public MouseButtonEvent
{
public:
    MouseButtonReleasedEvent(int button)
        : MouseButtonEvent(button) {}

    const std::string ToString() const override
    {
        std::stringstream ss;
        ss << "MouseButtonReleasedEvent: " << m_button;
        return ss.str();
    }

    EVENT_CLASS_TYPE(kMouseButtonReleased);
};
}
#pragma once

#include "event.h"

namespace hezel
{
class KeyEvent : public Event
{
public:
    int get_keycode() const
    {
        return m_keycode;
    }
    
    EVENT_CLASS_CATEGORY(kEventCategoryKeyBoard | kEventCategoryInput)
protected:
    KeyEvent(int keycode) : m_keycode(keycode) {}
    int m_keycode;
};

class KeyPressedEvent : public KeyEvent
{
public:
    KeyPressedEvent(int keycode, int repeat_count)
        : KeyEvent(keycode), m_repeat_count(repeat_count) {}
    
    int get_repeat_count() const { return m_repeat_count; }
    
    const std::string ToString() const override
    {
        std::stringstream ss;
        ss << "KeyPressedEvent: " << m_keycode << " (" << m_repeat_count << ")";
        return ss.str();
    }
    
    EVENT_CLASS_TYPE(kKeyPressed);
private:
    int m_repeat_count;
};

class KeyReleasedEvent : public KeyEvent
{
public:
    KeyReleasedEvent(int keycode)
        : KeyEvent(keycode) {}
    
    int get_repeat_count() const { return m_repeat_count; }
    
    const std::string ToString() const override
    {
        std::stringstream ss;
        ss << "KeyReleasedEvent: " << m_keycode;
        return ss.str();
    }
    
    EVENT_CLASS_TYPE(kKeyReleased);
private:
    int m_repeat_count;
};
}
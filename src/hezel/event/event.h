#pragma once

#include "hezel/core.h"
#include <spdlog/fmt/ostr.h>

namespace hezel
{
enum class EventType
{
    None = 0,
    kWindowClose, kWindowResize, kWindowFocus, kWindowDeFocus, kWindowMoved,
    kAppTick, kAppUpdate, kAppRender,
    kKeyPressed, kKeyReleased,
    kMouseButtonPressed, kMouseButtonReleased, kMouseMoved, kMouseScrolled,
};

enum EventCategory: int
{
    None = 0,
    kEventCategoryApplication = BIT(0),
    kEventCategoryInput = BIT(1),
    kEventCategoryKeyBoard = BIT(2),
    kEventCategoryMouse = BIT(3),
    kEventCategoryMouseButton = BIT(4),
};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
                               virtual EventType GetEventType() const override { return GetStaticType(); }\
                               virtual const std::string GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

class Event
{
    friend class EventDispatcher;

public:
    virtual EventType GetEventType() const = 0;
    virtual const std::string GetName() const = 0;
    virtual int GetCategoryFlags() const = 0;
    virtual const std::string ToString() const { return GetName(); };
    
    bool IsInCategory(EventCategory category)
    {
        return GetCategoryFlags() & category;
    }

    friend std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }

protected:
    bool m_handled = false;
};

class EventDispatcher
{
    template<typename T>
    using EventFn = std::function<bool(T&)>;

public:
    EventDispatcher(Event& event): m_event(event)
    {
    }
    
    template<typename T>
    bool Dispatch(EventFn<T> func)
    {
        if (m_event.GetEventType == T::GetStaticType())
        {
            m_event.m_handled = (*dynamic_cast<T*>(&m_event));
            return true;
        }
        return false;
    }

private:
    Event& m_event;
};

}

template <typename T>
struct fmt::formatter<
    T,
    std::enable_if_t<
        std::is_base_of_v<hezel::Event, T>,
        char
    >> : ostream_formatter {};
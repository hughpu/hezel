#pragma once

#include "hezel/window.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace hezel
{
class LinuxWindow : public Window
{
public:
    LinuxWindow(const WindowProps& props);
    virtual ~LinuxWindow();
    
    void OnUpdate() override;
    inline unsigned int get_width() const override { return m_data.width; }
    inline unsigned int get_height() const override { return m_data.height; }
    
    inline void SetEventCallback(const EventCallbackFn& callback) override { m_data.EventCallback = callback; }
    void SetVSync(bool enabled) override;
    bool IsVSync() const override;
    inline virtual void* GetNativeWindow() const override {
        return m_window;
    }

private:
    virtual void Init(const WindowProps& props);
    virtual void ShutDown();

private:
    GLFWwindow* m_window;
    
    struct WindowData
    {
        std::string title;
        unsigned int width, height;
        bool v_sync;
        EventCallbackFn EventCallback;
    };
    
    WindowData m_data;
};
}

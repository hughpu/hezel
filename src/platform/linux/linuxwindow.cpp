#include "linuxwindow.h"
#include "hezel/hzpch.h"

namespace hezel
{
static bool s_glfw_initialized = false;

Window* Window::Create(const WindowProps &props)
{
    return new LinuxWindow(props);
}

LinuxWindow::LinuxWindow(const WindowProps& props)
{
    Init(props);
}

LinuxWindow::~LinuxWindow()
{
    ShutDown();
}

void LinuxWindow::Init(const WindowProps& props)
{
    m_data.title = props.title;
    m_data.width = props.width;
    m_data.height = props.height;
    
    HZ_CORE_INFO("Creating window {0} ({1}, {2})", props.title, props.width, props.height);
    
    if (!s_glfw_initialized)
    {
        int success = glfwInit();
        HZ_CORE_ASSERT(success, "Could not initialize GLFW!");
        
        s_glfw_initialized = true;
    }
    
    m_window = glfwCreateWindow((int) props.width, (int) props.height, m_data.title.c_str(), nullptr, nullptr);
    HZ_CORE_ASSERT(m_window == nullptr, "failed to create window");

    glfwMakeContextCurrent(m_window);
    glfwSetWindowUserPointer(m_window, &m_data);
    SetVSync(true);
}

void LinuxWindow::ShutDown()
{
    glfwDestroyWindow(m_window);
}

void LinuxWindow::OnUpdate()
{
    glfwPollEvents();
    glfwSwapBuffers(m_window);
}

void LinuxWindow::SetVSync(bool enabled)
{
    if (enabled)
        glfwSwapInterval(1);
    else
        glfwSwapInterval(0);
    
    m_data.v_sync = enabled;
}

bool LinuxWindow::IsVSync() const
{
    return m_data.v_sync;
}

}
#include "linuxwindow.h"
#include "hezel/hzpch.h"
#include "hezel/event/application_event.h"
#include "hezel/event/key_event.h"
#include "hezel/event/mouse_event.h"
#include "imgui_impl_glfw.h"

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

static void GLFWErrorCallback(int error_code, const char* description)
{
    HZ_CORE_ERROR("GLFW Error ({0}):{1}", error_code, description);
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
        
        glfwSetErrorCallback(GLFWErrorCallback);
        s_glfw_initialized = true;
    }
    
    m_window = glfwCreateWindow((int) props.width, (int) props.height, m_data.title.c_str(), nullptr, nullptr);
    HZ_CORE_ASSERT(m_window == nullptr, "failed to create window");

    glfwMakeContextCurrent(m_window);
    int status = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    HZ_ASSERT(status, "glad failed to initialize");
    glfwSetWindowUserPointer(m_window, &m_data);
    SetVSync(true);
    

    glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
    {
        WindowData &data = *(WindowData*) glfwGetWindowUserPointer(window);
        data.width = width;
        data.height = height;

        WindowResizeEvent event(width, height);
        data.EventCallback(event);
    });
    

    glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
    {
        WindowData &data = *(WindowData*) glfwGetWindowUserPointer(window);
        WindowCloseEvent event;
        data.EventCallback(event);
    });
    

    glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods){
        WindowData &data = *(WindowData*) glfwGetWindowUserPointer(window);

        switch (action)
        {
        case GLFW_PRESS:
        {
            KeyPressedEvent event(key, 0);
            data.EventCallback(event);
            break;
        }
        case GLFW_RELEASE:
        {
            KeyReleasedEvent event(key);
            data.EventCallback(event);
            break;
        }
        case GLFW_REPEAT:
        {
            KeyPressedEvent event(key, 1);
            data.EventCallback(event);
            break;
        }
        
        default:
            break;
        }
    });

    
    glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods){
        WindowData &data = *(WindowData*) glfwGetWindowUserPointer(window);
        
        switch (action)
        {
        case GLFW_PRESS:
        {
            MouseButtonPressedEvent event(button);
            data.EventCallback(event);
            break;
        }
        case GLFW_RELEASE:
        {
            MouseButtonPressedEvent event(button);
            data.EventCallback(event);
            break;
        }
        }
    });

    
    glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xoffset, double yoffset){
        WindowData &data = *(WindowData*) glfwGetWindowUserPointer(window);
        
        MouseScrolledEvent event((float) xoffset, (float) yoffset);
        data.EventCallback(event);
    });
    

    glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xpos, double ypos){
        WindowData &data = *(WindowData*) glfwGetWindowUserPointer(window);
        
        MouseMovedEvent event((float) xpos, (float) ypos);
        data.EventCallback(event);
    });
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
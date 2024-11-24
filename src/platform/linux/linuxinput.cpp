#include "linuxinput.h"
#include "hezel/application.h"
#include <GLFW/glfw3.h>

namespace hezel
{
    HezelInput* HezelInput::s_input_ = new LinuxInput();

    bool LinuxInput::IsKeyImpressedImpl(int keycode)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool LinuxInput::IsMouseButtonPressedImpl(int button)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS;
    }
    
    std::pair<float, float> LinuxInput::GetMousePositionImpl()
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        return { float(xpos), float(ypos) };
    }
    
    float LinuxInput::GetMouseXImpl()
    {
        auto[x, _] = GetMousePositionImpl();
        return x;
    }

    float LinuxInput::GetMouseYImpl()
    {
        auto[_, y] = GetMousePositionImpl();
        return y;
    }
}

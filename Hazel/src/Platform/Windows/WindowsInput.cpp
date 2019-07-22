#include "hzpch.h"

#include "Hazel/Application.h"
#include "WindowsInput.h"

#include <GLFW/glfw3.h>

namespace Hazel {
  Input* Input::s_Instance = new WindowsInput();

  bool WindowsInput::IsKeyPressedImpl(int keyCode) {
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    auto state = glfwGetKey(window, keyCode);
    return state == GLFW_PRESS || state == GLFW_REPEAT;
  }

  bool WindowsInput::IsMouseButtonPressedImpl(int button) {
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    auto state = glfwGetMouseButton(window, button);
    return state == GLFW_PRESS;
  }
  
  float WindowsInput::GetMouseXImpl() {
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    return (float)xpos;
  }
  
  float WindowsInput::GetMouseYImpl() {
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    return (float)ypos;
  }

  std::pair<float, float> WindowsInput::GetMousePositionImpl() {
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    return std::make_pair<float, float>((float)xpos, (float)ypos);
  }

}
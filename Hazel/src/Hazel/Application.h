#pragma once

#include "Core.h"

#include "Window.h"
#include "Hazel/LayerStack.h"
#include "Event/Event.h"
#include "Hazel/Event/ApplicationEvent.h"

namespace Hazel {
 
  class HAZEL_API Application {
  public:
    Application();
    virtual ~Application();
    void Run();

    void OnEvent(Event& e);

    void PushLayer(Layer* layer);
    void PushOverlay(Layer* layer);
    
    inline static Application& Get() { return *s_Instance; }
    inline Window& GetWindow() { return *m_Window;  }

  private:
    static Application* s_Instance;
    bool OnWindowClose(WindowCloseEvent&e);

    std::unique_ptr<Window> m_Window;
    bool m_Running = true;
    LayerStack m_LayerStack;
  };

  // To be defined in client.
  Application* CreateApplication();
}

#include "hzpch.h"

#include "Renderer.h"
#include "VertexArray.h"

#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Hazel {

  VertexArray* VertexArray::Create() {

    switch (Renderer::GetAPI()) {
      case RendererAPI::API::None: HZ_CORE_ASSERT(false, "RendererAPI::None is not currently suppoerted."); return nullptr;
      case RendererAPI::API::OpenGL: return new OpenGLVertexArray();
    }

    HZ_CORE_ASSERT(false, "Uknown RendererAPI!");
    return nullptr;

  }



}
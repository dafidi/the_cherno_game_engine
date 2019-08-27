#pragma once

#include "Hazel/Renderer/Shader.h"

#include "glm/glm.hpp"

namespace Hazel {

  class OpenGLShader : public Shader {
  public:
    OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
    virtual ~OpenGLShader();

    virtual void Bind() const override;
    virtual void UnBind() const override;

    void UploadUniformInt(const std::string& name, const int value);
    void UploadUniformFloat(const std::string& name, const float value);
    void UploadUniformFloat2(const std::string& name, const glm::vec2& values);
    void UploadUniformFloat3(const std::string& name, const glm::vec3& values);
    void UploadUniformFloat4(const std::string& name, const glm::vec4& values);
    void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);
    void UploadUniformMat3(const std::string& name, const glm::mat3& matrix);

  private:
    uint32_t m_RendererID;

  };
}
#pragma once
#include "common.hpp"
#include "pch.hpp"

#include <string>

namespace myvk::bs {
class Shader {
public:
  VkPipelineShaderStageCreateInfo m_shaderInfo;
  VkShaderStageFlagBits           m_stage;
  std::string                     m_name;

  Shader() = default;
  Shader(std::string const& name, VkShaderStageFlagBits stage)
      : m_stage(stage), m_name(name){};
  ~Shader() = default;

  void create(VkDevice device, u32* code, size_t size,
              ccstr entryName = "main");

  template <typename T, typename = std::void_t<std::is_arithmetic<T>>>
  void create(VkDevice device, std::vector<T>& vec, ccstr entryName = "main") {
    this->create(device, reinterpret_cast<u32*>(vec.data()), vec.size());
  }

  void destroy(VkDevice device);
};
} // namespace myvk::bs

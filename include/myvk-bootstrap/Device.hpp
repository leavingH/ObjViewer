#pragma once
#include "common.hpp"
#include "pch.hpp"

namespace myvk_bs {
class Device {
public:
  vkb::Device         m_device;
  vkb::PhysicalDevice m_gpu;
  
  Device(vkb::PhysicalDevice gpu) : m_gpu(std::move(gpu)) {}
  ~Device() = default;
  void create(std::vector<ccstr> &layers, std::vector<ccstr> &extensions);
  void destroy();
};

} // namespace myvk_bs
#pragma once
#ifdef _WIN32
#define NOMINMAX
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <vulkan/vulkan.h>

#include <GLFW/glfw3.h>
#include <VkBootstrap.h>
#include <spdlog/spdlog.h>
#include <vk_mem_alloc.h>


#include <memory>
#include <vector>
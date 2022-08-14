#include "myvk-bootstrap/Swapchain.hpp"

namespace myvk_bs {
Swapchain::~Swapchain() {}

void Swapchain::create(u32 width, u32 height) {

  vkb::SwapchainBuilder builder{*m_device};

  auto result = builder.use_default_format_selection()
                    .set_desired_present_mode(VK_PRESENT_MODE_FIFO_KHR)
                    .set_desired_extent(width, height)
                    .build();
  assert(result.has_value());
  m_swapchain  = (result.value());
  m_images     = std::move(m_swapchain.get_images().value());
  m_imageViews = std::move(m_swapchain.get_image_views().value());
}
void Swapchain::destroy() {
  m_swapchain.destroy_image_views(m_imageViews);
  vkb::destroy_swapchain(m_swapchain);
}
} // namespace myvk_bs
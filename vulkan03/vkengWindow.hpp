#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace vkeng
{
	class vkengWindow
	{
	public:
		vkengWindow(int w, int h, std::string name);
		~vkengWindow();

		vkengWindow(const vkengWindow&) = delete; 
		vkengWindow& operator=(const vkengWindow&) = delete;

		bool shouldClose();
		void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);
		VkExtent2D getExtent() { return { static_cast<uint32_t>(width), static_cast<uint32_t>(height) }; }

	private:
		const int width;
		const int height;

		GLFWwindow*		window;
		std::string		windowName;

		void initWindow();
	};
}
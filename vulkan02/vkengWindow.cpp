#include "vkengWindow.hpp"

#include <stdexcept>

namespace vkeng
{
	vkengWindow::vkengWindow(int w, int h, std::string name) : width{ w }, height{ h }, windowName{ name }
	{
		initWindow();
	}

	vkengWindow::~vkengWindow()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void vkengWindow::initWindow()
	{
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	}

	bool vkengWindow::shouldClose() { return glfwWindowShouldClose(window); }


	void vkengWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface)
	{
		if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
		{
			throw std::runtime_error("failed to create window surface.");
		}
	}
}
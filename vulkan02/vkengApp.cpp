#pragma once

#include "vkengApp.hpp"

namespace vkeng
{
	vkengApp::vkengApp() {};
	vkengApp::~vkengApp() {};

	void vkengApp::run() 
	{
		while (!window.shouldClose())
		{
			glfwPollEvents();
		}
	};
}
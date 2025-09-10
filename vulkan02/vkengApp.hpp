#pragma once

#include "vkengWindow.hpp"

namespace vkeng
{
	class vkengApp
	{
	public:
		vkengApp();
		~vkengApp();

		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		void run();
	private:
		vkengWindow window{ WIDTH, HEIGHT, "Vulkan Engine" };
	};
}
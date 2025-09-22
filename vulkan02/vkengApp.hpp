#pragma once

#include <string>

#include "vkengWindow.hpp"
#include "vkengPipeline.hpp"

namespace vkeng
{
	class vkengApp
	{
	public:
		vkengApp();
		~vkengApp();

		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;
		const std::string VERT_PATH = "Shaders/simple_shader.vert.spv";
		const std::string FRAG_PATH = "Shaders/simple_shader.frag.spv";

		void run();
	private:
		vkengWindow window{ WIDTH, HEIGHT, "Vulkan Engine" };
		vkengDevice device{ window };
		vkengPipeline pipeline
		{
			device, 
			VERT_PATH, 
			FRAG_PATH, 
			vkengPipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)
		};
	};
}
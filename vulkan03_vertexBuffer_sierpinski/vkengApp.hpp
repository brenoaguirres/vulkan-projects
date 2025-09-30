#pragma once

#include "vkengWindow.hpp"
#include "vkengPipeline.hpp"
#include "vkengDevice.hpp"
#include "vkengSwapChain.hpp"
#include "vkengModel.hpp"

#include <string>
#include <memory>
#include <vector>

namespace vkeng
{
	class vkengApp
	{
	public:
		vkengApp();
		~vkengApp();

		vkengApp(const vkengApp&) = delete;
		vkengApp& operator=(const vkengApp&) = delete;

		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;
		const std::string VERT_PATH = "Shaders/simple_shader.vert.spv";
		const std::string FRAG_PATH = "Shaders/simple_shader.frag.spv";

		void run();
	private:
		vkengWindow window{ WIDTH, HEIGHT, "Vulkan Engine" };
		vkengDevice device{ window };
		vkengSwapChain swapChain{ device, window.getExtent() };
		std::unique_ptr<vkengPipeline> pipeline;
		VkPipelineLayout pipelineLayout;
		std::vector<VkCommandBuffer> commandBuffers;
		std::unique_ptr<vkengModel> model;

		void loadModels();
		void createPipelineLayout();
		void createPipeline();
		void createCommandBuffers();
		void drawFrame();
	};
}
#pragma once

#include "vkengApp.hpp"

#include <stdexcept>

namespace vkeng
{
	vkengApp::vkengApp() 
	{
		createPipelineLayout();
		createPipeline();
		createCommandBuffers();
	};
	vkengApp::~vkengApp() 
	{
		vkDestroyPipelineLayout(device.device(), pipelineLayout, nullptr);
	};

	void vkengApp::run() 
	{
		while (!window.shouldClose())
		{
			glfwPollEvents();
		}
	};

	void vkengApp::createPipelineLayout()
	{
		VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
		pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		pipelineLayoutInfo.setLayoutCount = 0;
		pipelineLayoutInfo.pSetLayouts = nullptr;
		pipelineLayoutInfo.pushConstantRangeCount = 0;
		pipelineLayoutInfo.pPushConstantRanges = nullptr;
		if (vkCreatePipelineLayout(device.device(), &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS)
		{
			throw std::runtime_error("failed to create pipeline layout!");
		}
	};

	void vkengApp::createPipeline()
	{
		auto pipelineConfig = vkengPipeline::defaultPipelineConfigInfo(swapChain.width(), swapChain.height());
		pipelineConfig.renderPass = swapChain.getRenderPass();
		pipelineConfig.pipelineLayout = pipelineLayout;
		pipeline = std::make_unique<vkengPipeline>(device, VERT_PATH, FRAG_PATH, pipelineConfig);
	};

	void vkengApp::createCommandBuffers()
	{

	};

	void vkengApp::drawFrame()
	{

	};
}
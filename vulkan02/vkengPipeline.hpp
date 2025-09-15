#pragma once

#include "vkengDevice.hpp"

#include <string>
#include <vector>

namespace vkeng
{
	struct PipelineConfigInfo {};
	class vkengPipeline
	{
	public:
		vkengPipeline(
			vkengDevice& device,
			const std::string& vertFilePath, 
			const std::string& fragFilePath, 
			const PipelineConfigInfo& configInfo
		);
		~vkengPipeline() {};

		vkengPipeline(const vkengPipeline&) = delete;
		void operator=(const vkengPipeline&) = delete;

		static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

	private:
		vkengDevice& Device;
		VkPipeline graphicsPipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;

		static std::vector<char> readFile(const std::string& filePath);
		void createGraphicsPipeline(
			const std::string& vertFilePath, 
			const std::string& fragFilePath,
			const PipelineConfigInfo& configInfo
		);
		void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);
	};
}
#pragma once

#include "vkengDevice.hpp"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>

#include <vector>

// Takes vertex data created by - or read in a file - on the cpu and allocate the memory and copy
// the data over to our device GPU for efficient rendering.

namespace vkeng
{
	class vkengModel
	{
	public:

		struct Vertex
		{
			glm::vec2 position;

			static std::vector<VkVertexInputBindingDescription> getBindingDescriptions();
			static std::vector<VkVertexInputAttributeDescription> getAttributeDescriptions();
		};

		struct Triangle
		{
			glm::vec2 a, b, c;
		};

		vkengModel(vkengDevice &device, const std::vector<Vertex> &vertices);
		~vkengModel();

		vkengModel(const vkengModel&) = delete;
		vkengModel& operator=(const vkengModel&) = delete;

		void bind(VkCommandBuffer commandBuffer);
		void draw(VkCommandBuffer commandBuffer);

	private:
		vkengDevice& device;
		VkBuffer vertexBuffer;
		VkDeviceMemory vertexBufferMemory;
		uint32_t vertexCount;

		void createVertexBuffers(const std::vector<Vertex> &vertices);
	};
}
#pragma once

#include "vkengModel.hpp"

namespace vkeng
{
	class vkengPatterns
	{
	public:
		static void sierpinski(const vkengModel::Triangle& t, int depth, std::vector<vkengModel::Vertex>& out);
	};
}
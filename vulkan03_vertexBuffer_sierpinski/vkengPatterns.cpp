#include "vkengPatterns.hpp"

namespace vkeng
{
	void vkengPatterns::sierpinski(const vkengModel::Triangle& t, int depth, std::vector<vkengModel::Vertex>& out)
	{
		if (depth == 0)
		{
			out.push_back({ t.a });
			out.push_back({ t.b });
			out.push_back({ t.c });
			return;
		}

		glm::vec2 ab = (t.a + t.b) * 0.5f;
		glm::vec2 bc = (t.b + t.c) * 0.5f;
		glm::vec2 ca = (t.c + t.a) * 0.5f;

		sierpinski({ t.a, ab, ca }, depth - 1, out);
		sierpinski({ ab, t.b, bc }, depth - 1, out);
		sierpinski({ ca, bc, t.c }, depth - 1, out);
	}
}
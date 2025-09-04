#version 450

layout(location = 0) in vec3 fragColor; // receives input variable from vertex shader
// name mustn't match, they'll be linked together using the indexes specified by the location directives
// the values for fragColor will be interpolated for the fragments between the vertices, resulting in gradient

layout(location = 0) out vec4 outColor; // specify output variable in the index of the framebuffer (0)

// The triangle produces by the positions from the vertex shader fills an area onscreen with fragments.
// This is invoked on these fragments to produce a color and depth for the framebuffers
void main()
{
	outColor = vec4(fragColor, 1.0);
	//outColor = vec4(1.0, 0.0, 0.0, 1.0); // color in red the entire fragment, colors are vec4 rgba 0 - 1
}
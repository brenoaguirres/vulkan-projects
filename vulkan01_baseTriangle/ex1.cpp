// Base Code

//#include <vulkan/vulkan.h> // vulkan header will work alone as well but won't show anything

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h> // used to create window and show gfx

#include <iostream> // report and propagate errors
#include <stdexcept> // report and propagate errors
#include <cstdlib> // EXIT_SUCCESS, EXIT_FAILURE

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class HelloTriangleApplication1
{

public:
	void run()
	{
		initWindow();
		mainLoop();
		cleanup();
	}

private:
	GLFWwindow* window;

	void initWindow()
	{
		glfwInit(); // init window library

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // no OpenGL context since we use Vulkan
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // disable resizing for now

		window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr); // create and init window - params: width, height, title, monitor (for fullscreen), only for OpenGL context
	}

	void mainLoop()
	{
		while (!glfwWindowShouldClose(window))
		{
			glfwPollEvents();
		}
	}

	void cleanup()
	{
		glfwDestroyWindow(window);

		glfwTerminate();
	}
};

int example1()
{
	HelloTriangleApplication1 app;

	try
	{
		app.run();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
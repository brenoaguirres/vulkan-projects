#include "vkengApp.hpp"

#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main()
{
	vkeng::vkengApp app{};

	try
	{
		app.run();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		return EXIT_FAILURE;
	}
}
#include "Engine.h"

int main(int argc, char* args[])
{
	try
	{
		Engine engine;
		engine.init();
		engine.start();
	
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (std::out_of_range & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (std::bad_alloc & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
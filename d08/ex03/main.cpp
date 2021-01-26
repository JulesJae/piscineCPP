#include "Interpreter.class.hpp"
#include <iostream>

int     main(int ac, char *av[])
{
	Interpreter		*interpret;

	if (ac != 2)
	{
		std::cout << "Usage: ./interpret <filename>\n";
		return (0);
	}
	interpret = new Interpreter(av[1]);
	try
	{
		interpret->readFile();
		interpret->interpretCode();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
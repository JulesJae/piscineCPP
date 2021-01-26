#include <string>
#include <iostream>
#include "Poland.hpp"


int			main(int ac, char *av[])
{
	Poland	p;

	if (ac != 2)
	{
		std::cout << "Usage: ./ft_poland \"Mathematic expression\"\n";
		return (0);
	}
	try {
		p.tokenizer(av[1]);
		p.postfixTokens();
		p.calculate();
	} catch (std::exception const &e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
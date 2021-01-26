#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int		main()
{
	std::vector<int>	v{2, 19, 12, 42, 55};
	std::list<int>		l{55, 72, 19, 42, 85};

	try
	{
		int result = easyfind(v, 42);
		std::cout << "Vector : " << result << "\n";
		result = easyfind(l, 42);
		std::cout << "List : " << result << "\n";
		result = easyfind(l, 5);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Nice catch\n";
	}
	
}
#include <iostream>

int			main()
{
	std::string		str("HI THIS IS BRAIN");
	std::string		*pstr;
	std::string		&rstr = str;

	pstr = &str;
	std::cout << "str = " << str << std::endl;
	std::cout << "pstr = " << *pstr << std::endl;
	std::cout << "rstr = " << rstr << std::endl;
	return (0);
}
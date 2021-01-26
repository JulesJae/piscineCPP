#include "Mutantstack.hpp"
#include <iostream>
#include <stack>

void	print_stack(Mutantstack<std::string> &stack)
{
	Mutantstack<std::string>::iterator	it_s(stack.begin());
	Mutantstack<std::string>::iterator	it_e(stack.end());

	for (; it_s != it_e; it_s++)
		std::cout << *it_s << "\n";
}

int     main()
{
	Mutantstack<std::string>	first;
	Mutantstack<std::string>	second;

	first.push("Le ");
	first.push("C ");
	first.push("C' est ");
	first.push("Trop ");
	first.push("Naze ");
	second.push("Ouai ");
	second.push("Mais ");
	second.push("Le ");
	second.push("C++ ");
	second.push("Est ");
	second.push("Cool ");
	second.push("Aussi!");
	first.pop();
	first.push("Bien");
	print_stack(first);
	std::cout << "\n SWAP \n\n";
	first.swap(second);
	print_stack(first);
	std::cout << "\n\n";
	std::stack<std::string>	s(first);
	std::cout << "Real Stack to = " << s.top() << "\n";
}
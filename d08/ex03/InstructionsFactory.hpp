#ifndef INSTRUCTIONSFACTORY_HPP
# define INSTRUCTIONSFACTORY_HPP

# include <string>
# include "IInstruction.hpp"

class InstructionsFactory
{
	public:
		InstructionsFactory();
		InstructionsFactory(InstructionsFactory const &obj);
		virtual ~InstructionsFactory();

		InstructionsFactory			&operator=(InstructionsFactory const &rhs);

		IInstruction				*create(char inst, char **ptr);
		
	private:
};

#endif
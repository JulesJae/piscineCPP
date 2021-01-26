#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"
# include <string>

class Human
{
	public:
		Human();
		std::string		identifier() const;
		Brain const		&getBrain();


	private:
		Brain const		*_brain;
};

#endif

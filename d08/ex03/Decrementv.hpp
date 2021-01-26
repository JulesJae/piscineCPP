#ifndef DECREMENTV_HPP
# define DECREMENTV_HPP

# include <string>
# include "IInstruction.hpp"

class Decrementv: public IInstruction
{
	public:
		Decrementv(char **head);
		Decrementv(Decrementv const &obj);
		virtual ~Decrementv();

		Decrementv			&operator=(Decrementv const &rhs);

		virtual int		exec();
		
	private:
		Decrementv();
		char				**_head;
	
};

#endif
#ifndef INCREMENTV_HPP
# define INCREMENTV_HPP

# include <string>
# include "IInstruction.hpp"

class Incrementv: public IInstruction
{
	public:
		Incrementv(char **head);
		Incrementv(Incrementv const &obj);
		virtual ~Incrementv();

		Incrementv			&operator=(Incrementv const &rhs);

		virtual int		exec();
		
	private:
		Incrementv();
		char				**_head;
	
};

#endif
#ifndef INCREMENTP_HPP
# define INCREMENTP_HPP

# include <string>
# include "IInstruction.hpp"

class Incrementp: public IInstruction
{
	public:
		Incrementp(char **head);
		Incrementp(Incrementp const &obj);
		virtual ~Incrementp();

		Incrementp			&operator=(Incrementp const &rhs);

		virtual int		exec();
		
	private:
		Incrementp();
		char				**_head;
	
};

#endif
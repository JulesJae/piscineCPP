#ifndef WRITEV_HPP
# define WRITEV_HPP

# include <string>
# include "IInstruction.hpp"

class Writev: public IInstruction
{
	public:
		Writev(char **head);
		Writev(Writev const &obj);
		virtual ~Writev();

		Writev			&operator=(Writev const &rhs);

		virtual int		exec();
		
	private:
		Writev();
		char				**_head;
	
};

#endif
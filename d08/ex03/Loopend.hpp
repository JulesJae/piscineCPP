#ifndef LOOPEND_HPP
# define LOOPEND_HPP

# include <string>
# include "IInstruction.hpp"

class Loopend: public IInstruction
{
	public:
		Loopend(char **head);
		Loopend(Loopend const &obj);
		virtual ~Loopend();

		Loopend			&operator=(Loopend const &rhs);

		virtual int		exec();
		
	private:
		Loopend();
		char				**_head;
	
};

#endif
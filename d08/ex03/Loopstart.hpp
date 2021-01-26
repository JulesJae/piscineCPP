#ifndef LOOPSTART_HPP
# define LOOPSTART_HPP

# include <string>
# include "IInstruction.hpp"

class Loopstart: public IInstruction
{
	public:
		Loopstart(char **head);
		Loopstart(Loopstart const &obj);
		virtual ~Loopstart();

		Loopstart			&operator=(Loopstart const &rhs);

		virtual int		exec();
		
	private:
		Loopstart();
		char				**_head;
	
};

#endif
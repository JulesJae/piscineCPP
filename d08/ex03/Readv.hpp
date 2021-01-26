#ifndef READV_HPP
# define READV_HPP

# include <string>
# include "IInstruction.hpp"

class Readv: public IInstruction
{
	public:
		Readv(char **head);
		Readv(Readv const &obj);
		virtual ~Readv();

		Readv			&operator=(Readv const &rhs);

		virtual int		exec();
		
	private:
		Readv();
		char				**_head;
	
};

#endif
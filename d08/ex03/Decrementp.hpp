#ifndef DECREMENTP_HPP
# define DECREMENTP_HPP

# include <string>
# include "IInstruction.hpp"

class Decrementp: public IInstruction
{
	public:
		Decrementp(char **head);
		Decrementp(Decrementp const &obj);
		virtual ~Decrementp();

		Decrementp			&operator=(Decrementp const &rhs);

		virtual int		exec();
		
	private:
		Decrementp();
		char				**_head;
	
};

#endif
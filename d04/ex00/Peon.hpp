#ifndef PEON_HPP
# define PEON_HPP

# include <string>
# include "Victim.hpp"

class Peon: public Victim
{
	public:
		Peon(std::string const &name);
		Peon(Peon const &obj);
		virtual ~Peon();
		
		Peon			&operator=(Peon const &rhs);

		virtual void	getPolymorphed() const;

		
	private:
	
};

#endif
#ifndef DERIVED_HPP
# define DERIVED_HPP

# include <string>
# include "Victim.hpp"

class Derived: public Victim
{
	public:
		Derived(std::string const &name);
		Derived(Derived const &obj);
		virtual ~Derived();
		
		Derived			&operator=(Derived const &rhs);

		virtual void	getPolymorphed() const;

		
	private:
	
};

#endif
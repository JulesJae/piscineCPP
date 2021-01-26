#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <string>
# include <iostream>
# include "Victim.hpp"

class Sorcerer
{
	public:
		std::string		name;
		std::string		title;

		Sorcerer(std::string const &name, std::string const &title);
		Sorcerer(Sorcerer const &obj);
		~Sorcerer();

		Sorcerer			&operator=(Sorcerer const &rhs);

		void				polymorph(Victim const &) const;

		
	private:
		Sorcerer();
	
};

std::ostream				&operator<<(std::ostream &o, Sorcerer const &sorcerer);

#endif
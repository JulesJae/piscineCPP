#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <string>

class Victim
{
	public:
		std::string		name;

		Victim(std::string const &name);
		Victim(Victim const &obj);
		virtual ~Victim();

		Victim			&operator=(Victim const &rhs);

		virtual void		getPolymorphed() const;
		
	private:
		Victim();
	
};

std::ostream				&operator<<(std::ostream &o, Victim const &vikos);

#endif
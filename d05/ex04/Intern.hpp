#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

# define NUMBER_OF_FORMS 3

class Intern
{
	typedef Form	*(Intern::* fnConstruct)(std::string target) const;

	public:
		Intern();
		Intern(Intern const &obj);
		virtual ~Intern();

		Intern			&operator=(Intern const &rhs);

		Form			*makeForm(std::string name, std::string target) const;
		Form			*createPresident(std::string target) const;
		Form			*createRobot(std::string target) const;
		Form			*createShrub(std::string target) const;

	private:
		static std::string		_formNames[NUMBER_OF_FORMS];
		static fnConstruct		_constructors[NUMBER_OF_FORMS];
};

#endif
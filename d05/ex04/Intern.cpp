#include "Intern.hpp"

std::string			Intern::_formNames[NUMBER_OF_FORMS] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

Intern::fnConstruct	Intern::_constructors[NUMBER_OF_FORMS] = {
	&Intern::createShrub,
	&Intern::createRobot,
	&Intern::createPresident
};

Intern::Intern() 
{

}

Intern::Intern(Intern const &obj)
{
	*this = obj;
}

Intern::~Intern()
{

}

Form			*Intern::createShrub(std::string target) const
{
	return new ShrubberyCreationForm(target);
}

Form			*Intern::createRobot(std::string target) const
{
	return new RobotomyRequestForm(target);
}

Form			*Intern::createPresident(std::string target) const
{
	return new PresidentialPardonForm(target);
}

Form			*Intern::makeForm(std::string name, std::string target) const
{
	for (int i = 0; i < NUMBER_OF_FORMS; i++)
	{
		if (Intern::_formNames[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*(Intern::_constructors[i]))(target);
		}
	}
	std::cout << "Sorry my dear " << name << " is not in my competences.\n";
	return nullptr;
}

Intern			&Intern::operator=(Intern const &rhs)
{
	if (this != &rhs)
		return *this;
	return *this;
}

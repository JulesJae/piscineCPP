#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("Presidential", 25, 5),_target(target) 
{

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &obj): Form(obj)
{
	*this = obj;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void							PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	Form::canExec(executor);
	std::cout << this->_target << " has been forgiven by Zafod Beeblerox\n";
}

std::string						PresidentialPardonForm::getTarget() const { return this->_target; }

PresidentialPardonForm			&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	this->_target = rhs.getTarget();
	return *this;
}

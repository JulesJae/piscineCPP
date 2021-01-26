#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("Robotomy", 72, 45),_target(target) 
{

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj): Form(obj)
{
	*this = obj;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void							RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	Form::canExec(executor);
	std::cout << "* BZZzz BZZzz BZZzz * " << this->_target << " has been well Robotomized * BZZzz BZZzz BZZzz *\n";
}

std::string						RobotomyRequestForm::getTarget() const { return this->_target; }

RobotomyRequestForm			&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	this->_target = rhs.getTarget();
	return *this;
}

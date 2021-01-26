#include "Form.hpp"
#include <iostream>

Form::Form(std::string name, int sign, int exec)
{
	if (sign > LOWER_GRADE || exec > LOWER_GRADE)
		throw Form::GradeTooLowException();
	else if (sign < HIGHER_GRADE || exec < HIGHER_GRADE)
		throw Form::GradeTooHighException();
	this->_name = name;
	this->_signed = false;
	this->_signGradeRequired = sign;
	this->_execGradeRequired = exec;
	std::cout << "Form created\n";
}

Form::Form(Form const &obj)
{
	std::cout << "Form created\n";
	*this = obj;
}

Form::~Form()
{
	std::cout << "Form destructed\n";
}

std::string		Form::getName() const { return this->_name; }
bool			Form::getSigned() const { return this->_signed; }
int				Form::getSignGrade() const { return this->_signGradeRequired; }
int				Form::getExecGrade() const { return this->_execGradeRequired; }

void			Form::setSignGrade(int grade)
{
	if (grade > LOWER_GRADE)
		throw Form::GradeTooLowException();
	else if (grade < HIGHER_GRADE)
		throw Form::GradeTooHighException();
	this->_signGradeRequired = grade;
}

void			Form::setExecGrade(int grade)
{
	if (grade > LOWER_GRADE)
		throw Form::GradeTooLowException();
	else if (grade < HIGHER_GRADE)
		throw Form::GradeTooHighException();
	this->_execGradeRequired = grade;
}

void			Form::beSigned(Bureaucrat &b)
{
	int			grade(b.getGrade());

	if (grade > this->getSignGrade())
		throw Form::GradeTooLowException();
	b.signForm(*this);
	this->_signed = true;
}

Form::GradeTooHighException::GradeTooHighException() throw() {}

char const					*Form::GradeTooHighException::what() const throw() { return "Form: Grade too high"; }

Form::GradeTooLowException::GradeTooLowException() throw() {}

char const					*Form::GradeTooLowException::what() const throw() { return "Form: Grade too low"; }

Form			&Form::operator=(Form const &rhs)
{
	this->_execGradeRequired = rhs.getExecGrade();
	this->_signGradeRequired = rhs.getExecGrade();
	this->_name = rhs.getName();
	this->_signed = rhs.getSigned();
	return *this;
}

std::ostream			&operator<<(std::ostream &o, Form const &f)
{
	o << f.getName() << ", signed: " << f.getSigned() << ", signedGrade: " << f.getSignGrade() << ", execGrade: " << f.getExecGrade() << std::endl;
	return o;
}


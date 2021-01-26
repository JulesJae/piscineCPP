#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(LOWER_GRADE)
{
	std::cout << "Bureaucrat constructed\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	if (grade < HIGHER_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > LOWER_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_name = name;
	this->_grade = grade;
	std::cout << "Bureaucrat constructed\n";
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj)
{
	*this = obj;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructed\n";
}

std::string const	Bureaucrat::getName() const { return this->_name; }
int 				Bureaucrat::getGrade() const { return this->_grade; }

void				Bureaucrat::upGrade()
{
	if (this->_grade != HIGHER_GRADE)
		this->_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void				Bureaucrat::downGrade()
{
	if (this->_grade != LOWER_GRADE)
		this->_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat			&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	this->_name = rhs.getName();
	this->_grade = rhs.getGrade();
	return *this;
}

Bureaucrat::GradeTooHighException::GradeTooHighException() throw() {}

char const					*Bureaucrat::GradeTooHighException::what() const throw() { return "Grade too high"; }

Bureaucrat::GradeTooLowException::GradeTooLowException() throw() {}

char const					*Bureaucrat::GradeTooLowException::what() const throw() { return "Grade too low"; }

std::ostream				&operator<<(std::ostream &o, Bureaucrat const &b)
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
	return o;
}
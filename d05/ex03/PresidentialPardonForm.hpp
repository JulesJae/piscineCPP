#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm: public Form
{
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &obj);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);

		virtual void		execute(Bureaucrat const &executor)const;
		std::string			getTarget()const;
		
	private:
		std::string			_target;	
};

#endif
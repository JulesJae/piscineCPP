#ifndef FUCKINGFORM_HPP
# define FUCKINGFORM_HPP

# include <string>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm: public Form
{
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &obj);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);

		void				execute(Bureaucrat const &executor) const;
		std::string			getTarget()const;
		
	private:
		std::string			_target;	
};

#endif
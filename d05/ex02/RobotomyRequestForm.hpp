#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm: public Form
{
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &obj);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm	&operator=(RobotomyRequestForm const &rhs);

		virtual void		execute(Bureaucrat const &executor) const;
		std::string			getTarget()const;
		
	private:
		std::string			_target;	
};

#endif
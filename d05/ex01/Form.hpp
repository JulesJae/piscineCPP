#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <exception>
# include <iostream>
# include "include.hpp"
# include "Bureaucrat.hpp"

# define HIGHER_GRADE 1
# define LOWER_GRADE 150

class Form
{
	public:
		Form(std::string name, int sign, int exec);
		Form(Form const &obj);
		virtual ~Form();

		Form			&operator=(Form const &rhs);

		std::string		getName()const;
		bool			getSigned()const;
		int				getExecGrade() const;
		int				getSignGrade() const;
		void			setExecGrade(int);
		void			setSignGrade(int);
		void			beSigned(Bureaucrat &b);

		class GradeTooHighException: public std::exception 
		{
			public:
				GradeTooHighException() throw();

				virtual char const	*what() const throw();
		};
		class GradeTooLowException: public std::exception 
		{
			public:
				GradeTooLowException() throw();
	
				virtual char const	*what() const throw();
		};

		
	private:
		std::string		_name;
		bool			_signed;
		int				_signGradeRequired;
		int				_execGradeRequired;
	
};

std::ostream			&operator<<(std::ostream &o, Form const &f);

#endif
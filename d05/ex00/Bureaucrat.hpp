#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>
# include <iostream>

# define HIGHER_GRADE 1
# define LOWER_GRADE 150

class Bureaucrat
{
	public:
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &obj);
		virtual ~Bureaucrat();

		Bureaucrat			&operator=(Bureaucrat const &rhs);

		std::string const	getName() const;
		int					getGrade() const;
		void				upGrade();
		void				downGrade();

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
		std::string			_name;
		int					_grade;
	
};

std::ostream				&operator<<(std::ostream &o, Bureaucrat const &b);

#endif
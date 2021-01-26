#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

# include <string>
# include "Bureaucrat.hpp"
# include "Intern.hpp"
# include "Form.hpp"

class OfficeBlock
{
	public:
		OfficeBlock();
		OfficeBlock(Intern *intern, Bureaucrat *signatory, Bureaucrat *executor);
		virtual ~OfficeBlock();

		void		doBureaucraty(std::string const &formName, std::string const &target) const;
		void		setIntern(Intern *intern);
		void		setSignatory(Bureaucrat *signatory);
		void		setExecutor(Bureaucrat *executor);
		
	private:
		Intern		*_intern;
		Bureaucrat	*_signatory;
		Bureaucrat	*_executor;
	
};

#endif
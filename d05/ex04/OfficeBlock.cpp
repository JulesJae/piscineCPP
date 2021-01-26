#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(): _intern(nullptr), _signatory(nullptr), _executor(nullptr)
{

}

OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *signatory, Bureaucrat *executor): _intern(intern)
	, _signatory(signatory), _executor(executor)
{

}

OfficeBlock::~OfficeBlock()
{

}

void			OfficeBlock::doBureaucraty(std::string const &formName, std::string const &target) const
{
	Form	*form;

	if (this->_executor == nullptr || this->_intern == nullptr || this->_signatory == nullptr)
	{
		std::cout << "Office not complete\n";
		return;
	}
	form = this->_intern->makeForm(formName, target);
	if (form != nullptr)
	{
		try
		{
			std::cout << *form;
			form->beSigned(*this->_signatory);
			this->_executor->executeForm(*form);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
			std::cout << "OfficeBlock: sorry for that we will now hire a more qualify employee\n";
		}
		
	}
}

void			OfficeBlock::setExecutor(Bureaucrat *executor)
{
	std::cout << "OfficeBlock: new executor has been hire\n";
	std::cout << *executor;
	this->_executor = executor;
}

void			OfficeBlock::setIntern(Intern *intern)
{
	std::cout << "OfficeBlock: new intern has been hire\n";
	this->_intern = intern;
}

void			OfficeBlock::setSignatory(Bureaucrat *signatory)
{
	std::cout << "OfficeBlock: new signatory has been hire\n";
	std::cout << *signatory;
	this->_signatory = signatory;
}
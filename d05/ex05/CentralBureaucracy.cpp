#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy()
{
	this->_idxOffice = 0;
	this->_signatory = true;
	this->_targetQueue = nullptr;
	this->_waiters->head = nullptr;
	this->_waiters->last = nullptr;
	this->_waiters->waiter = nullptr;
}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const &obj)
{
	*this = obj;
}

CentralBureaucracy::~CentralBureaucracy()
{
	for (int i = 0; i < this->_idxOffice; i++)
	{
		delete this->_offices[i].
	}
}

void						CentralBureaucracy::feed(Bureaucrat *bureaucrat)
{
	t_waiter	*waiter;


	waiter = new t_waiter();
	waiter->bureaucrat = bureaucrat;
	waiter->next = nullptr;
	if (this->_waiters->head == nullptr)
	{
		this->_waiters->head = waiter;
		this->_waiters->last = waiter;
	}
	std::cout << "Cenral Bureaucracy is happy to eat " << bureaucrat->getName() <<"!\n";
	this->_placeOrWait(waiter);
}

void						CentralBureaucracy::_placeOrWait(CentralBureaucracy::t_waiter *waiter)
{
	int		i(this->_idxOffice);

	if (i <= 20)
	{
		if (this->_signatory)
		{
			this->_offices[i].setIntern(new Intern());
			this->_offices[i].setSignatory(waiter->bureaucrat);
			waiter->wait = false;
			this->_signatory = false;
		} else 
		{
			this->_offices[i].setExecutor(waiter->bureaucrat);
			this->_signatory = true;
			this->_idxOffice++;
			std::cout << "Central Bureaucracy: Excellent we have a new full OfficeBlock, number of blocks: " << i + 1 << "!\n";
		}
	} else if (this->_waiters->waiter == nullptr)
		this->_waiters->waiter = waiter;
	this->_waiters->last->next = waiter;
	this->_waiters->last = waiter;
}

void						CentralBureaucracy::queueUp(std::string const formName, std::string const target)
{
	CentralBureaucracy::t_queueUp *elem;

	elem = new t_queueUp();
	elem->formName = formName;
	elem->target = target;
	elem->next = nullptr;
	if (this->_targetQueue == nullptr)
		this->_targetQueue = elem;
}

CentralBureaucracy			&CentralBureaucracy::operator=(CentralBureaucracy const &rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}

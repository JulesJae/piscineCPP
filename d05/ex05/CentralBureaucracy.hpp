#ifndef CENTRALBUREAUCRACY_HPP
# define CENTRALBUREAUCRACY_HPP

# include <string>
# include "OfficeBlock.hpp"

class CentralBureaucracy
{
	typedef struct s_queueUp
	{
		std::string		&formName;
		std::string		&target;
		struct s_queueUp	*next;
	}				t_queueUp;

	typedef struct s_waiter
	{
		Bureaucrat			*bureaucrat;
		bool				wait;
		struct s_waiter		*next;
	}				t_waiter;

	typedef struct s_waiters
	{
		CentralBureaucracy::t_waiter	*head;
		CentralBureaucracy::t_waiter	*last;
		CentralBureaucracy::t_waiter	*waiter;
	}				t_waiters;

	public:
		CentralBureaucracy();
		CentralBureaucracy(CentralBureaucracy const &obj);
		virtual ~CentralBureaucracy();

		CentralBureaucracy			&operator=(CentralBureaucracy const &rhs);

		void						feed(Bureaucrat *Bureaucrat);
		void						queueUp(std::string const formName, std::string const target);

		
	private:
		OfficeBlock						_offices[20];
		CentralBureaucracy::t_queueUp	*_targetQueue;
		CentralBureaucracy::t_waiters	*_waiters;
		int								_idxOffice;
		bool							_signatory;

		void							_placeOrWait(CentralBureaucracy::t_waiter *waiter);
	
};

#endif
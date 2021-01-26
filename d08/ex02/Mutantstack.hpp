#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <vector>
# include <stack>
# include <deque>

template< typename T >
class Mutantstack: public std::stack<T>
{

	public:
		typedef				typename std::deque<T>::iterator iterator;

		Mutantstack(): std::stack<T>() {}

		Mutantstack(Mutantstack<T> &obj): std::stack<T>(obj)
		{
		}

		virtual ~Mutantstack(){}

		Mutantstack<T>				&operator=(Mutantstack<T> const &rhs)
		{
			std::stack<T>::operator=(rhs);
		}

		Mutantstack<T>::iterator 	begin() { return this->c.begin(); }
		Mutantstack<T>::iterator	end() { return this->c.end(); }

	
};

#endif
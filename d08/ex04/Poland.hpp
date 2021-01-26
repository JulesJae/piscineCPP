#ifndef POLAND_HPP
# define POLAND_HPP

# include "TokenQueue.hpp"
# include "Token.hpp"
# include <string>

class Poland
{
	private:
		static std::string		_operator;
		TokenQueue				_queue;
		std::deque<int>			_stack;

		void					_incrementQueue(std::deque<Token*> &o);
		void					_decrementQueue(std::deque<Token*> &o);
		void					_printStack();
		void					_addInStack();
		void					_subInStack();
		void					_mulInStack();
		void					_divInStack();
		void					_makeOpStack(Token *t);
		void					_pushOp(std::deque<Token*> &ops, std::deque<Token*> &queue);

	public:
		Poland();
		Poland(Poland const &p);
		~Poland();

		void					tokenizer(char *s);
		void					postfixTokens();
		void					calculate();
};

#endif
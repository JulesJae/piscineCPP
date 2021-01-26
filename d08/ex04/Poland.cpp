#include "Poland.hpp"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <iomanip>

std::string     Poland::_operator = "+-*/()";

Poland::Poland() {}
Poland::~Poland() {}

void			Poland::_printStack()
{
	size_t		end(this->_stack.size());
	size_t		i(0);

	std::cout << "ST ";
	while (i < end)
	{
		std::cout << this->_stack[i];
		i++;
		std::cout << ((i == end) ? "]\n" : " ");
	}
}

void			Poland::_addInStack()
{
	int			lhs;
	int			rhs;

	rhs = this->_stack.front();
	this->_stack.pop_front();
	lhs = this->_stack.front();
	this->_stack.pop_front();
	this->_stack.push_front(lhs + rhs);
}

void			Poland::_subInStack()
{
	int			lhs;
	int			rhs;

	rhs = this->_stack.front();
	this->_stack.pop_front();
	lhs = this->_stack.front();
	this->_stack.pop_front();
	this->_stack.push_front(lhs - rhs);
}

void			Poland::_mulInStack()
{
	int			lhs;
	int			rhs;

	rhs = this->_stack.front();
	this->_stack.pop_front();
	lhs = this->_stack.front();
	this->_stack.pop_front();
	this->_stack.push_front(lhs * rhs);
}

void			Poland::_divInStack()
{
	int			lhs;
	int			rhs;

	rhs = this->_stack.front();
	this->_stack.pop_front();
	lhs = this->_stack.front();
	this->_stack.pop_front();
	this->_stack.push_front(lhs / rhs);
}

void			Poland::_makeOpStack(Token *t)
{
	switch (t->c)
	{
		case '+':
			this->_addInStack();
			break;
		case '-':
			this->_subInStack();
			break;
		case '*':
			this->_mulInStack();
			break;
		default:
			this->_divInStack();
	}
}

void            Poland::tokenizer(char *s)
{
	std::string	str(s);
	int			val;
	size_t		i(0);
	size_t		len;
	size_t		sz;

	len = str.size();
	while (i < len)
	{
		if (std::isdigit(str[i]) || (str[i] == '-' && std::isdigit(str[i + 1])))
		{
			val = std::stoi(&str[i], &sz);
			this->_queue.addToken(new Token(val));
			i += sz;
			continue;
		} else if (this->_operator.find(str[i]) != std::string::npos)
		{
			if (!this->_queue.addToken(new Token(str[i])))
				throw std::runtime_error("Multiple operators detected");
		}
		 else if (str[i] != ' ')
			throw std::runtime_error("Bad character detected");
		i++;	
	}
	if (this->_queue.checkSyntax())
		this->_queue.printTokens("Tokens");
	else
		throw std::runtime_error("Parenthesis unmatched");
}

void				Poland::_pushOp(std::deque<Token*> &ops, std::deque<Token*> &queue)
{
	Token							*op;

	op = ops.front();
	if (op && op->value == 0)
	{
		queue.push_back(op);
		ops.pop_front();
	}
}

void				Poland::postfixTokens()
{
	std::deque<Token*>				ops;
	std::deque<Token*>				queue;
	Token							*elem;

	while ((elem = this->_queue.queue.front()))
	{
		if (elem->type == Token::NUM)
		{
			queue.push_back((elem));
			this->_pushOp(ops, queue);
		}
		else if (elem->type == Token::OP)
			ops.push_front(elem);
		else if (elem->type == Token::PAR_OP)
			this->_incrementQueue(ops);
		else if (elem->type == Token::PAR_CL)
		{
			this->_decrementQueue(ops);
			this->_pushOp(ops, queue);
		}
		this->_queue.queue.pop_front();
	}
	this->_queue.queue = queue;
	this->_queue.printTokens("Postfix");
}

void				Poland::calculate()
{
	for (size_t i = 0; i < this->_queue.queue.size(); i++)
	{
		std::cout << "I " << std::setw(7);
		this->_queue.queue[i]->printToken();
		std::cout << " | "  << std::setw(11) << this->_queue.queue[i]->action << " | ";
		switch (this->_queue.queue[i]->type)
		{
			case Token::NUM:
				this->_stack.push_front(this->_queue.queue[i]->value);
				break;
			case Token::OP:
				this->_makeOpStack(this->_queue.queue[i]);
			default:
				break;
		}
		this->_printStack();
	}
	std::cout << "Result: " << this->_stack.front() << '\n';
}

void				Poland::_incrementQueue(std::deque<Token*> &o)
{
	for (size_t i = 0; i < o.size(); i++)
		o[i]->value += 1;
}

void				Poland::_decrementQueue(std::deque<Token*> &o)
{
	for (size_t i = 0; i < o.size(); i++)
		o[i]->value -= 1;
}
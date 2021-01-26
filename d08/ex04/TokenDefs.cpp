#include <string>
#include <deque>
#include <iostream>
#include "Token.hpp"
#include "TokenQueue.hpp"

Token::Token(int i): type(NUM), value(i), action("OP Push") {};

Token::Token(char c)
{
	if (c == '(')
		this->type = PAR_OP;
	else if (c == ')')
		this->type = PAR_CL;
	else
	{
		this->type = OP;
		if (c == '+')
			this->action = "OP Add";
		else if (c == '-')
			this->action = "OP Substract";
		else if (c == '*')
			this->action = "OP Multiply";
		else if (c == '/')
			this->action = "OP Divise";
	}
	this->c = c;
	this->value = 0;
}

void		Token::printToken()
{
	if (this->type == NUM)
		std::cout << "Num(" << this->value << ")";
	else if (this->type == PAR_OP)
		std::cout << "ParOpen";
	else if (this->type == PAR_CL)
		std::cout << "ParClose";
	else
		std::cout << "Op(" << this->c << ")";
}

TokenQueue::TokenQueue(): parenthesis(0) {};

bool		TokenQueue::addToken(Token *t)
{
	if (this->lastType == t->OP && t->type == t->OP)
		return false;
	if (t->type == t->PAR_OP)
		this->parenthesis++;
	else if (t->type == t->PAR_CL)
		this->parenthesis--;
	this->queue.push_back(t);
	this->lastType = t->type;
	return true;
}

void		TokenQueue::printTokens(std::string title)
{
	std::deque<Token*>::iterator	it_s;
	std::deque<Token*>::iterator	it_e;

	it_s = this->queue.begin();
	it_e = this->queue.end();
	std::cout << title << ": ";
	while (it_s != it_e)
	{
		(*it_s)->printToken();
		it_s++;
		std::cout << ((it_s == it_e) ? '\n' : ' ');
	}
}

bool		TokenQueue::checkSyntax() { return !this->parenthesis; }


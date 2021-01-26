#ifndef TOKENQUEUE_HPP
# define TOKENQUEUE_HPP

#include "Token.hpp"
#include <deque>

struct TokenQueue
{
    std::deque<Token*>		queue;
	Token::type_e			lastType;
	int						parenthesis;

    TokenQueue();
    bool                    addToken(Token *t);
    bool                    checkSyntax();
    void                    printTokens(std::string title);
};

#endif
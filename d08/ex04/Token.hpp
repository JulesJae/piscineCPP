#ifndef TOKEN_HPP
# define TOKEN_HPP

# include <string>

struct Token
{
    enum type_e
	{
		NUM,
		OP,
		PAR_OP,
		PAR_CL
	};
    
    enum type_e     type;
    int             value;
    char            c;
    std::string     action;

    Token(int i);
    Token(char c);
    void            printToken();
};

#endif

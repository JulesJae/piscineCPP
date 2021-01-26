#ifndef PERSON_H
# define PERSON_H

# include "includes.hpp"

class Person
{
	std::string  firstname, lastname, nickname, login, address, email, phone, birthday, favoriteMeal
		, underwearColor, darkestSecret;

	public:

	enum Type
	{
		FIRST,
		LAST,
		NICK,
		LOGIN,
		ADDR,
		EMAIL,
		PHONE,
		BIRTH,
		MEAL,
		UNDER_C,
		DARK_S
	};

	void        setInfo(Type t, std::string val);
	std::string getInfo(Type t);
};

# endif
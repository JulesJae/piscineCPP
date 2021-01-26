#include "Person.hpp"

std::string Person::getInfo(Person::Type t)
{
	switch (t)
	{
		case Person::FIRST:
			return this->firstname;
		
		case Person::LAST:
			return this->lastname;

		case Person::NICK:
			return this->nickname;

		case Person::LOGIN:
			return this->login;

		case Person::ADDR:
			return this->address;

		case Person::EMAIL:
			return this->email;

		case Person::PHONE:
			return this->phone;

		case Person::BIRTH:
			return this->birthday;

		case Person::MEAL:
			return this->favoriteMeal;

		case Person::UNDER_C:
			return this->underwearColor;

		case Person::DARK_S:
			return this->darkestSecret;
	}
}

void Person::setInfo(Person::Type t, std::string val)
{
	switch (t)
	{
		case Person::FIRST:
			this->firstname = val;
			break;
		
		case Person::LAST:
			this->lastname = val;
			break;

		case Person::NICK:
			this->nickname = val;
			break;

		case Person::LOGIN:
			this->login = val;
			break;

		case Person::ADDR:
			this->address = val;
			break;

		case Person::EMAIL:
			this->email = val;
			break;

		case Person::PHONE:
			this->phone = val;
			break;

		case Person::BIRTH:
			this->birthday = val;
			break;

		case Person::MEAL:
			this->favoriteMeal = val;
			break;

		case Person::UNDER_C:
			this->underwearColor = val;
			break;

		case Person::DARK_S:
			this->darkestSecret = val;
			break;
	}
}
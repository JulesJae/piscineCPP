#include "Phonebook.hpp"
#include <iomanip>

Phonebook::Phonebook():i(-1)
{
}

void Phonebook::addContactInfo(std::string infos, Person::Type t)
{
	std::string	val;

	while (1)
	{
		std::cout << infos << ":\n";
		getline(std::cin, val);
		if (val.size() >= 1)
			break;
		std::cout << "You have to enter a value\n";
	}
	this->contacts[this->i].setInfo(t, val);
}

void Phonebook::add()
{
	if (this->i < CONTACT_MAX - 1)
		this->i += 1;
	std::cout << "Please enter following informations:\n";
	this->addContactInfo("Firstname", Person::FIRST);
	this->addContactInfo("Lastname", Person::LAST);
	this->addContactInfo("Nickname", Person::NICK);
	this->addContactInfo("Login", Person::LOGIN);
	this->addContactInfo("Address", Person::ADDR);
	this->addContactInfo("Email", Person::EMAIL);
	this->addContactInfo("Phone", Person::PHONE);
	this->addContactInfo("Birthday", Person::BIRTH);
	this->addContactInfo("Favorite meal", Person::MEAL);
	this->addContactInfo("Underwear color", Person::UNDER_C);
	this->addContactInfo("Darkest secret", Person::DARK_S);
	std::cout << "Contact correctly added\n\n";
}

std::string Phonebook::reduceWord(std::string s)
{
	if (s.size() > 10)
	{
		s = s.substr(0, 10);
		s[9] = '.';
	}
	return s;
}

void Phonebook::printContactDesc()
{
	int		i(0);
	std::string	val;

	while (i <= this->i)
	{
		std::cout << " | " << std::setw(10) << i;
		val = this->reduceWord(this->contacts[i].getInfo(Person::FIRST));
		std::cout << " | " << std::setw(10) << val;
		val = this->reduceWord(this->contacts[i].getInfo(Person::LAST));
		std::cout << " | " << std::setw(10) << val;
		val = this->reduceWord(this->contacts[i].getInfo(Person::NICK));
		std::cout << " | " << std::setw(10) << val << " |\n";
		i++;
	}
}

void Phonebook::printContact(int index)
{
	Person p(this->contacts[index]);

	std::cout << "Firstname: " << p.getInfo(Person::FIRST) << std::endl;
	std::cout << "Lastname: " << p.getInfo(Person::LAST) << std::endl;
	std::cout << "Nickname: " << p.getInfo(Person::NICK) << std::endl;
	std::cout << "Login: " << p.getInfo(Person::LOGIN) << std::endl;
	std::cout << "Address: " << p.getInfo(Person::ADDR) << std::endl;
	std::cout << "Email: " << p.getInfo(Person::EMAIL) << std::endl;
	std::cout << "Phone number: " << p.getInfo(Person::PHONE) << std::endl;
	std::cout << "Birthday: " << p.getInfo(Person::BIRTH) << std::endl;
	std::cout << "Favorite meal: " << p.getInfo(Person::MEAL) << std::endl;
	std::cout << "Underwear color: " << p.getInfo(Person::UNDER_C) << std::endl;
	std::cout << "Darkest Secret: " << p.getInfo(Person::DARK_S) << std::endl;
	std::cout << std::endl;
}

void Phonebook::search()
{
	int		index(-1);
	std::string	str;

	if (this->i < 0)
	{
		std::cout << "You have no contact in your Phonebook\n";
		return ;
	}
	std::cout << " | " << std::setw(10) << "index";
	std::cout << " | " << std::setw(10) << "firstname";
	std::cout << " | " << std::setw(10) << "lastname";
	std::cout << " | " << std::setw(10) << "nickname" << " |\n";
	this->printContactDesc();
	while (index < 0 || index > this->i)
	{
		std::cout << "\nEnter index value for seeing more details (0 - " << this->i << "):\n";
		getline(std::cin, str);
		try {
			index = stoi(str);
		} catch (std::invalid_argument& e) {
			index = -1;
		} catch (std::out_of_range& e) {
			index = -1;
		}
	}
	this->printContact(index);
}

void Phonebook::start()
{
	std::string	cmd;

	while (1)
	{
		std::cout << "Would you please enter a valid command (ADD, SEARCH, EXIT):\n";
		getline(std::cin, cmd);
		if (cmd == "ADD")
			this->add();
		else if (cmd == "SEARCH")
			this->search();
		else if (cmd == "EXIT")
			break;
		else
			std::cout << cmd << ": Invalid command\n\n";
	}
}
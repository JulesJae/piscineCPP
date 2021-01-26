#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Person.hpp"

# define CONTACT_MAX 8

class Phonebook
{
    Person		contacts[CONTACT_MAX];
    int			i;

	void		add();
	void		addContactInfo(std::string info, Person::Type t);
	void		printContactDesc();
	void		printContact(int index);
	std::string	reduceWord(std::string s);
	void		search();

    public:

	Phonebook();
    void    	start();
};

#endif
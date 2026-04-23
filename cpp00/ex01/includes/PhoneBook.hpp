#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <cstring>
#include <iostream>
#include <iomanip>
#include <limits>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contact[8] ;
	int		index;
public:
	PhoneBook();
	~PhoneBook();
	void addContact();
	void searchContact() const;
};

#endif
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <cstring>
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact _contact[8] ;
	int		_index;
	int		_count;
public:
	PhoneBook();
	~PhoneBook();
	void addContact();
	void searchContact() const;
};

#endif
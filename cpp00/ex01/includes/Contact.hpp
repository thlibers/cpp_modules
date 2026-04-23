#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <cstring>
#include <iostream>
#include <iomanip>
#include <limits>
#include "PhoneBook.hpp"

class Contact
{
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _darkestSecret;
public:
	Contact();
	~Contact();
	void setFirstName(std::string &value);
	void setLastName(std::string &value);
	void setNickName(std::string &value);
	void setPhoneNumber(std::string &value);
	void setDarkestSecret(std::string &value);
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;
};

#endif
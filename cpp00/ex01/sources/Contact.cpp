#include "../includes/PhoneBook.hpp"

Contact::Contact()
{
	// std::cout << "constructor called" << std::endl;
}

Contact::~Contact()
{
	// std::cout << "destructor called" << std::endl;
}

void Contact::setFirstName(std::string &value)
{
	this->_firstName = value;
}

void Contact::setLastName(std::string &value)
{
	this->_lastName = value;
}

void Contact::setNickName(std::string &value)
{
	this->_nickName = value;
}

void Contact::setPhoneNumber(std::string &value)
{
	this->_phoneNumber = value;
}

void Contact::setDarkestSecret(std::string &value)
{
	this->_darkestSecret = value;
}

std::string Contact::getFirstName() const
{
	return this->_firstName;
}

std::string Contact::getLastName() const
{
	return this->_lastName;
}

std::string Contact::getNickName() const
{
	return this->_nickName;
}

std::string Contact::getPhoneNumber() const
{
	return this->_phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return this->_darkestSecret;
}

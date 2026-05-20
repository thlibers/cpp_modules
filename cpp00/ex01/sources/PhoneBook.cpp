#include "../includes/PhoneBook.hpp"

#include <cstdlib>

static std::string formatField(const std::string &value)
{
	if (value.length() > 10)
		return value.substr(0, 9) + ".";
	return value;
}

static bool isPositiveInteger(const std::string &input)
{
	if (input.empty())
		return false;
	for (std::string::size_type i = 0; i < input.length(); ++i)
	{
		if (input[i] < '0' || input[i] > '9')
			return false;
	}
	return true;
}

PhoneBook::PhoneBook()
{
	this->_index = 0;
	this->_count = 0;
	// std::cout << "constructor called" << std::endl;
}

PhoneBook::~PhoneBook()
{
	// std::cout << "destructor called" << std::endl;
}

void PhoneBook::addContact()
{
	std::string input;
	int num = this->_index;

	std::cout << "Enter contact info" << std::endl;
	while (true)
	{
		std::cout << "FirstName : ";
			if (!std::getline(std::cin, input))
				return;
			if (input.empty())
				continue;
			this->_contact[num].setFirstName(input);
			break;
	}
	while (true)
	{
		std::cout << "LastName : ";
			if (!std::getline(std::cin, input))
				return;
			if (input.empty())
				continue;
			this->_contact[num].setLastName(input);
			break;
	}
	while (true)
	{
		std::cout << "NickName : ";
			if (!std::getline(std::cin, input))
				return;
			if (input.empty())
				continue;
			this->_contact[num].setNickName(input);
			break;
	}
	while (true)
	{
		std::cout << "PhoneNumber : ";
		if (!std::getline(std::cin, input))
			return;
		if (input.empty())
			continue;
		this->_contact[num].setPhoneNumber(input);
		break;
	}
	while (true)
	{
		std::cout << "DarkestSecret : ";
		if (!std::getline(std::cin, input))
			return;
		if (input.empty())
			continue;
		this->_contact[num].setDarkestSecret(input);
		break;
	}
	this->_index = (this->_index + 1) % 8;
	if (this->_count < 8)
		this->_count++;
}

void PhoneBook::searchContact() const
{
	int index;
	std::string input;

	if (this->_count == 0)
	{
		std::cout << "PhoneBook is empty" << std::endl;
		return;
	}
	std::cout << std::setw(10) << "Index" << "|"
		<< std::setw(10) << "FirstName" << "|"
		<< std::setw(10) << "LastName" << "|"
		<< std::setw(10) << "NickName" << std::endl;
	for (int i = 0; i < this->_count; ++i)
	{
		std::cout << std::setw(10) << i << "|"
			<< std::setw(10) << formatField(this->_contact[i].getFirstName()) << "|"
			<< std::setw(10) << formatField(this->_contact[i].getLastName()) << "|"
			<< std::setw(10) << formatField(this->_contact[i].getNickName()) << std::endl;
	}
	std::cout << "Choose an index: ";
	if (!std::getline(std::cin, input))
		return;
	if (!isPositiveInteger(input))
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	index = ::atoi(input.c_str());
	if (index < 0 || index >= this->_count)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	std::cout << "FirstName: " << this->_contact[index].getFirstName() << std::endl;
	std::cout << "LastName: " << this->_contact[index].getLastName() << std::endl;
	std::cout << "NickName: " << this->_contact[index].getNickName() << std::endl;
	std::cout << "PhoneNumber: " << this->_contact[index].getPhoneNumber() << std::endl;
	std::cout << "DarkestSecret: " << this->_contact[index].getDarkestSecret() << std::endl;
}

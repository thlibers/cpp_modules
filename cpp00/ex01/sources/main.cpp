#include "../includes/PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string input;

	while (true)
	{
		if (std::cin.eof())
			break;
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, input))
			break;
		if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.searchContact();
		else if (input == "EXIT")
			break;
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}

#include "ScalarConverter.hpp"
#include <climits>

ScalarConverter::ScalarConverter()
{
	// std::cout << "Constructor Called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	// std::cout << "Destructor Called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &Cpy)
{
	// std::cout << "Copy Constructor Called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &Cpy)
{
	// std::cout << "Copy Assignement Constructor Called" << std::endl;
	return (*this);
}

// Functions

static bool isChar(std::string string)
{
	if (string.size() == 3 && string[0] == '\'' && string[2] == '\'')
		return true;
	return false;
}

// static bool isInt(std::string string)
// {
// }

static bool isFloat(std::string string)
{
	if (string.find('f', string.size() - 1))
		return true;
	return false;
}

static bool isDouble(std::string string)
{
	if (string.find('.') != std::string::npos)
		return true;
	return false;
}

static void printChar(char value)
{
	if ((value >= 0 && value <= 31) || value == 127)
		std::cout << "char:" << "non displayable" << std::endl;
	else if (value > 31 && value < 127)
		std::cout << "char:" << "'" << value << "'" << std::endl;
	else
		std::cout << "char:" << "impossible" << std::endl;
}

static void printInt(std::string string, int value)
{
	if (value >= INT_MIN && value <= INT_MAX)
		std::cout << "int:" << value << std::endl;
	else if (string == "-inf" || string == "+inf")
		std::cout << "int:" << string << std::endl;
	else
		std::cout << "int:" << "impossible" << std::endl;
}

static void printFloat()
{
	
}

static void printDouble()
{
	
}

static void convert(std::string string)
{

}

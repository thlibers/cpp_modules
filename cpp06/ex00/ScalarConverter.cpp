#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <sstream>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &Cpy)
{
	(void)Cpy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &Cpy)
{
	(void)Cpy;
	return (*this);
}

static bool isPrintable(char c)
{
	return (c >= 32 && c <= 126);
}

static bool isChar(std::string const &string)
{
	if (string.size() == 1 && !std::isdigit(static_cast<unsigned char>(string[0])))
		return true;
	if (string.size() == 3 && string[0] == '\'' && string[2] == '\'' && isPrintable(string[1]))
		return true;
	return false;
}

static bool isFloat(std::string const &string)
{
	if (string == "nanf" || string == "+inff" || string == "-inff")
		return true;
	if (string.empty() || string[string.size() - 1] != 'f')
		return false;
	if (string.find('.') == std::string::npos)
		return false;
	return true;
}

static bool isDouble(std::string const &string)
{
	if (string == "nan" || string == "+inf" || string == "-inf")
		return true;
	if (string.find('.') == std::string::npos)
		return false;
	return true;
}

static void printChar(double value)
{
	char c;

	if (value != value || value < 0 || value > 127)
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	c = static_cast<char>(value);
	if (!isPrintable(c))
	{
		std::cout << "char: Non displayable" << std::endl;
		return;
	}
	std::cout << "char: '" << c << "'" << std::endl;
}

static void printInt(double value)
{
	if (value != value || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}
	std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void printFloat(std::string const &string, double value)
{
	if (string == "nan" || string == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		return;
	}
	if (string == "+inf" || string == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		return;
	}
	if (string == "-inf" || string == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		return;
	}
	std::cout << "float: " << value;
	if (value == std::floor(value))
		std::cout << ".0";
	std::cout << 'f' << std::endl;
}

static void printDouble(std::string const &string, double value)
{
	if (string == "nan" || string == "nanf")
	{
		std::cout << "double: nan" << std::endl;
		return;
	}
	if (string == "+inf" || string == "+inff")
	{
		std::cout << "double: +inf" << std::endl;
		return;
	}
	if (string == "-inf" || string == "-inff")
	{
		std::cout << "double: -inf" << std::endl;
		return;
	}
	std::cout << "double: " << value;
	if (value == std::floor(value))
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::convert(std::string string)
{
	double value;

	if (isChar(string))
	{
		if (string.size() == 3)
			value = static_cast<double>(string[1]);
		else
			value = static_cast<double>(string[0]);
	}
	else if (isFloat(string))
		value = std::strtod(string.substr(0, string.size() - 1).c_str(), 0);
	else if (isDouble(string))
		value = std::strtod(string.c_str(), 0);
	else
		value = static_cast<double>(std::strtol(string.c_str(), 0, 10));
	printChar(value);
	printInt(value);
	printFloat(string, value);
	printDouble(string, value);
}
